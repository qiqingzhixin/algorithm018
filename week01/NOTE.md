学习笔记

[201020]
第一遍 比较含有退格的字符串
采用栈的思想但是没有采用封装好的栈，定义了一个变量，作为栈顶，如果不是#则加1，如果是则出栈。
最后比较两个字符串是否相等。
背诵双指针方法

[201021]
两个数之和
自己写采用的暴力查询，确实比较慢
参考官网，发现可以采用hash表的方式，简单高效(背诵)

[201022]
- 两两交换其中的相邻节点 第一次
- 比较含有退格的字符串

[201024]


## homework

### 改写Deque 代码
位置在 homwork/改写Deque的代码.java
### Queue源码分析
继承了Collection 接口
#### 接口中的方法有 

```java
public interface Queue<E> extends Collection<E> {
    /**
    * 在头添加一个元素，如果添加失败抛异常
    */
    boolean add(E e);

    /**
     * 在头添加一个元素，成功返回true 失败返回false
     */
    boolean offer(E e);

    /**
     * 删除队列的头元素，成功返回该元素，队列为空抛异常
     */
    E remove();

    /**
     * 删除队列的头元素，成功返回头元素，队列为空返回null 不抛异常
     */
    E poll();

    /**
     * 查看头元素，如果队列为空则抛异常
     */
    E element();

    /**
     * 查看头元素，如果队列为空返回null
     */
    E peek();
}

```
#### Queue 是一个接口实现类有

- AbstractQueue
- ArrayBlockingQueue
- ArrayDeque
- ConcurrentLinkedDeque
- ConcurrentLinkedQueue
- DelayQueue
- LinkedBlockingDeque
- LinkedBlockingQueue
- LinkedList
- LinkedTransferQueue
- PriorityBlockingQueue
- PriorityQueue
- SynchronousQueue

#### 分析PriorityQueue源码

特点

- 基于优先级堆
- 通过Comparator方法提供比较规则
- 不允许粗放null元素
- 不是线程安全，线程安全可以使用PriorityBlockQueue.java

##### 源码分析

**属性**

```java
/**
* 默认容量
*/
private static final int DEFAULT_INITIAL_CAPACITY = 11;

/**
* 存放元素的数据
*/
transient Object[] queue; // non-private to simplify nested class access

/**
* 元素的个数
*/
private int size = 0;

/**
* 比较器
*/
private final Comparator<? super E> comparator;

/**
* 操作的次数
*/
transient int modCount = 0; // non-private to simplify nested class access

```



**构造函数** 

```java
/**
* ===分析构造函数=== 
*/
private static final int DEFAULT_INITIAL_CAPACITY = 11;
/**
* 默认构造函数 
*/
public PriorityQueue() {
    this(DEFAULT_INITIAL_CAPACITY, null);
}

/**
* 可以设置容量的构造函数
*/
public PriorityQueue(int initialCapacity) {
    this(initialCapacity, null);
}

/**
* 提供比较器的构造函数
*/
public PriorityQueue(Comparator<? super E> comparator) {
    this(DEFAULT_INITIAL_CAPACITY, comparator);
}

/**
* 可以设置容量并且提供比较器的构造函数
*/
public PriorityQueue(int initialCapacity,
                     Comparator<? super E> comparator) {
    // Note: This restriction of at least one is not actually needed,
    // but continues for 1.5 compatibility
    if (initialCapacity < 1)
        throw new IllegalArgumentException();
    this.queue = new Object[initialCapacity];
    this.comparator = comparator;
}

/**
* 将集合放入有限队列
*/
@SuppressWarnings("unchecked")
public PriorityQueue(Collection<? extends E> c) {
    /**
    * 如果是有序集合，使用有序集合的比较器
    * 初始化优先队列
    */
    if (c instanceof SortedSet<?>) {
        SortedSet<? extends E> ss = (SortedSet<? extends E>) c;
        this.comparator = (Comparator<? super E>) ss.comparator();
        initElementsFromCollection(ss);
    }
    /**
    * 如果是优先队列 使用该优先队列的比较器
    * 初始化队列
    */
    else if (c instanceof PriorityQueue<?>) {
        PriorityQueue<? extends E> pq = (PriorityQueue<? extends E>) c;
        this.comparator = (Comparator<? super E>) pq.comparator();
        initFromPriorityQueue(pq);
    }
    else {
        /**
        * 其他容器则将比较器赋值为null
        * 初始化队列
        */
        this.comparator = null;
        initFromCollection(c);
    }
}
/**
* 使用优先级做初始化队列
*/
@SuppressWarnings("unchecked")
public PriorityQueue(PriorityQueue<? extends E> c) {
    this.comparator = (Comparator<? super E>) c.comparator();
    initFromPriorityQueue(c);
}
/**
* 使用有序集合初始化队列
*/
@SuppressWarnings("unchecked")
public PriorityQueue(SortedSet<? extends E> c) {
    this.comparator = (Comparator<? super E>) c.comparator();
    initElementsFromCollection(c);
}
/**
* ===分析初始化函数===
*/
/**
* 针对有序集合做处理
*/
private void initElementsFromCollection(Collection<? extends E> c) {
    Object[] a = c.toArray();
    //如果取出的元素不是Object[] 则使用Arrays.copyOf 方法进行获取
    if (a.getClass() != Object[].class)
        a = Arrays.copyOf(a, a.length, Object[].class);
    int len = a.length;
    /**
    * 如果元素长度为1 时元素不能为空
    * 如果比较器存在时，所有元素不能为空
    */
    if (len == 1 || this.comparator != null)
        for (int i = 0; i < len; i++)
            if (a[i] == null)
                throw new NullPointerException();
    // 这个为什么不排序
    this.queue = a;
    this.size = a.length;
}
/**
* 针对优先队列做处理
*/
private void initFromPriorityQueue(PriorityQueue<? extends E> c) {
    if (c.getClass() == PriorityQueue.class) {
        this.queue = c.toArray();
        this.size = c.size();
    } else {
        initFromCollection(c);
    }
}
/**
* 针对普通集合做处理
*/
private void initFromCollection(Collection<? extends E> c) {
    initElementsFromCollection(c);
    //构造小顶堆
    heapify();
}
/**
* 堆排序的具体实现
*/
private void heapify() {
    for (int i = (size >>> 1) - 1; i >= 0; i--)
        siftDown(i, (E) queue[i]);
}
/**
* 
*/
private void siftDown(int k, E x) {
    if (comparator != null)
        //设置比较器的排序
        siftDownUsingComparator(k, x);
    else
        //没有设置比较器的排序
        siftDownComparable(k, x);
}
/**
* 没有设置比较器的排序
*/
private void siftDownComparable(int k, E x) {
    //使用元素的比较器
    Comparable<? super E> key = (Comparable<? super E>)x;
    int half = size >>> 1;        // loop while a non-leaf
    while (k < half) {
        int child = (k << 1) + 1; // assume left child is least
        Object c = queue[child];
        int right = child + 1;
        if (right < size &&
            ((Comparable<? super E>) c).compareTo((E) queue[right]) > 0)
            c = queue[child = right];
        if (key.compareTo((E) c) <= 0)
            break;
        queue[k] = c;
        k = child;
    }
    queue[k] = key;
}
/**
* 设置比较器的排序
*/
private void siftDownUsingComparator(int k, E x) {
    int half = size >>> 1;
    while (k < half) {
        int child = (k << 1) + 1;
        Object c = queue[child];
        int right = child + 1;
        if (right < size &&
            comparator.compare((E) c, (E) queue[right]) > 0)
            c = queue[child = right];
        if (comparator.compare(x, (E) c) <= 0)
            break;
        queue[k] = c;
        k = child;
    }
    queue[k] = x;
}
```

#### add()函数和offer()是一个函数

```java
/**
* 添加一个函数
*/
public boolean add(E e) {
    return offer(e);
}

/**
* 添加一个函数
*/
public boolean offer(E e) {
    if (e == null)
        throw new NullPointerException();
    modCount++;
    int i = size;
    //如果元素个数大于数组长度 就进行扩展
    if (i >= queue.length)
        grow(i + 1);
    size = i + 1;
    第一个元素放到开头
    if (i == 0)
        queue[0] = e;
    else
        //自底向上
        siftUp(i, e);
    return true;
}
/**
* 
*/
private void grow(int minCapacity) {
    int oldCapacity = queue.length;
    //小的话加一倍，大的话加百分之50;
    int newCapacity = oldCapacity + ((oldCapacity < 64) ?
                                     (oldCapacity + 2) :
                                     (oldCapacity >> 1));
    // 如果超过最大数组的上限，重新定义新的容量
    if (newCapacity - MAX_ARRAY_SIZE > 0)
        newCapacity = hugeCapacity(minCapacity);
    queue = Arrays.copyOf(queue, newCapacity);
}
/**
* 最小容量 大于最大数组就是用 Integer类型中最大的，否则就是用最大数组的值
*/
private static int hugeCapacity(int minCapacity) {
    if (minCapacity < 0) // overflow
        throw new OutOfMemoryError();
    return (minCapacity > MAX_ARRAY_SIZE) ?
        Integer.MAX_VALUE :
    MAX_ARRAY_SIZE;
}
/**
* 
*/
private void siftUp(int k, E x) {
    //设置了比较器
    if (comparator != null)
        siftUpUsingComparator(k, x);
    else
        //没有设置比较器
        siftUpComparable(k, x);
}
/**
* 自底向上 遍历父节点，小于父节点就做交换，大于父节点就停止交换
*/
private void siftUpUsingComparator(int k, E x) {
    while (k > 0) {
        int parent = (k - 1) >>> 1;
        Object e = queue[parent];
        if (comparator.compare(x, (E) e) >= 0)
            break;
        queue[k] = e;
        k = parent;
    }
    queue[k] = x;
}
```

#### peek()

```java
public E peek() {
    //如果没有元素返回null，有元素返回第一个元素
    return (size == 0) ? null : (E) queue[0];
}
```

####  remove(Object o)

```java
public boolean remove(Object o) {
    //查找该元素位置
    int i = indexOf(o);
    if (i == -1)
        //元素不存在
        return false;
    else {
        //元素存在，进行移除
        removeAt(i);
        return true;
    }
}
//查找一个该元素的位置
private int indexOf(Object o) {
    if (o != null) {
        for (int i = 0; i < size; i++)
            if (o.equals(queue[i]))
                return i;
    }
    return -1;
}

/**
* 移除一个位置上的元素
*/
private E removeAt(int i) {
    // assert i >= 0 && i < size;
    modCount++;
    int s = --size;
    if (s == i) 
        // 移除最后一个
        queue[i] = null;
    else {
        //取出最后一个元素
        E moved = (E) queue[s];
        queue[s] = null;
        //自顶向下 操作
        siftDown(i, moved);
        //如果位置没有改变可能需要 自底向上操作
        if (queue[i] == moved) {
            siftUp(i, moved);
            //这里为什么要做一个这样的判断？？？
            if (queue[i] != moved)
                return moved;
        }
    }
    return null;
}
```

#### contains(Object o) 函数

```java
public boolean contains(Object o) {
    return indexOf(o) != -1;
}
```

####  toArray() 函数

```java
/**
*不指定类型
*/
public Object[] toArray() {
    return Arrays.copyOf(queue, size);
}

/**
*指定类型
*/
public <T> T[] toArray(T[] a) {
    final int size = this.size;
    //长度不够重新建一个数组
    if (a.length < size)
        // Make a new array of a's runtime type, but my contents:
        return (T[]) Arrays.copyOf(queue, size, a.getClass());
    //复制数组 源数组，源数组初始位置，目标数组，目标数组初始位置，复制长度
    System.arraycopy(queue, 0, a, 0, size);
    if (a.length > size)
        a[size] = null;
    return a;
}
```

#### poll() 函数

```java
/**
* 弹出第一个元素
*/
public E poll() {
    if (size == 0)
        return null;
    int s = --size;
    modCount++;
    E result = (E) queue[0];
    E x = (E) queue[s];
    queue[s] = null;
    if (s != 0)
        siftDown(0, x);
    return result;
}
```

### 分析的一些意外之处

- add 就是offer
- 弹出是poll

## 删除重复项

```C++
int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    int id = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[id] != nums[i]) {
            nums[++id]=nums[i];
        }
    }
    return id+1;
}
```


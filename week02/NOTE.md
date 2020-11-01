学习笔记

## 分析HashMap 中的get，put方法

### get 方法分析

```java
public V get(Object key) {
    Node<K,V> e;
    return (e = getNode(hash(key), key)) == null ? null : e.value;
}


final Node<K,V> getNode(int hash, Object key) {
    //做初始化
    Node<K,V>[] tab; Node<K,V> first, e; int n; K k;
    //表不为null 并且表中有元素并且 hash值对应的元素不能为null
    if ((tab = table) != null && (n = tab.length) > 0 &&
            (first = tab[(n - 1) & hash]) != null) {
        // 传入的hash要和当前的first一致 并且key值要和传入的key相等，说明第一个元素就是要找的元素。
        if (first.hash == hash && // always check first node
                ((k = first.key) == key || (key != null && key.equals(k))))
            return first;
        //如果first元素不是，则需要找下面的元素。
        if ((e = first.next) != null) {
            //堆实现的
            if (first instanceof TreeNode)
                //堆实现的
                return ((TreeNode<K,V>)first).getTreeNode(hash, key);
            //链表实现的
            do {
                
                if (e.hash == hash &&
                        ((k = e.key) == key || (key != null && key.equals(k))))
                    return e;
            } while ((e = e.next) != null);
        }
    }
    //最后没有找到
    return null;
}
/**
* 采用树实现的则通过递归方式进行遍历。
*/
final TreeNode<K,V> getTreeNode(int h, Object k) {
        return ((parent != null) ? root() : this).find(h, k, null);
}
```
### put 方法进行分析

```java
//基本方法
public V put(K key, V value) {
    //算出key的hash值，
    return putVal(hash(key), key, value, false, true);
}
final V putVal(int hash, K key, V value, boolean onlyIfAbsent,
                   boolean evict) {
    //如果表为空则新建表
    HashMap.Node<K,V>[] tab; HashMap.Node<K,V> p; int n, i;
    if ((tab = table) == null || (n = tab.length) == 0)
        n = (tab = resize()).length;
    //表中对应的节点为空则键节点
    if ((p = tab[i = (n - 1) & hash]) == null)
        tab[i] = newNode(hash, key, value, null);
    else {
        //如果也有节点则
        HashMap.Node<K,V> e; K k;
        
        if (p.hash == hash &&
                ((k = p.key) == key || (key != null && key.equals(k))))
            //找到对应的hash并且是第一个，将至赋给e
            e = p;
        else if (p instanceof HashMap.TreeNode)
            //如果是堆，怎放入堆中。
            e = ((HashMap.TreeNode<K,V>)p).putTreeVal(this, tab, hash, key, value);
        else {
            //剩下的是hash相同但是不是第一个node或者hash不相等
            for (int binCount = 0; ; ++binCount) {
                if ((e = p.next) == null) {
                    //如果p.next==null 说明到底了，创建一个新的节点
                    p.next = newNode(hash, key, value, null);
                    if (binCount >= TREEIFY_THRESHOLD - 1) // -1 for 1st
                        //如果里面的数据大于8了，就将其改成堆
                        treeifyBin(tab, hash);
                    break;
                }
                //表中创建第一个元素
                if (e.hash == hash &&
                        ((k = e.key) == key || (key != null && key.equals(k))))
                    break;
                p = e;
            }
        }
        //如果e！=null 说明存放成功
        if (e != null) { // existing mapping for key
            V oldValue = e.value;
            if (!onlyIfAbsent || oldValue == null)
                e.value = value;
            afterNodeAccess(e);
            return oldValue;
        }
    }
    //数量加1
    ++modCount;
    if (++size > threshold)
        resize();
    afterNodeInsertion(evict);
    return null;
}

```

### 异位词

主要思想就是用过map记录每一个字符出现的频率
两个字符串，
- 首先要保证两个字符串的长度必须相等
- 第一个是加操作
- 第二个字符串是减操作
- 最后查看map中是否又存在非零的数
如果存在非零说明这两个字符串不是异位词。
如果都是零则说明是异位词。

由于这里的可以确定只有小写字母，所有也可以开辟一个长度为26的int类型进行统计。

### 两个数之和
#### map
主要思想使用map尽快查找出与之对应的数。
如果没有将该数字存放到到map中再用下一个数进行寻找map中是否有与之对应的数

#### 排序+双指针
先排序然后通过双指针的形式进行遍历。

## 异位词分组

基本思路排序，加map

## 丑数

1. 暴力
2. 动态规划

主要思路 建一个丑数表，每新的一个丑数产生必将是之前的丑数乘 2 3 5 其中一个。

使用三个指针，index2,index3,index5 分别从0遍历这个丑数表，取其中最小的丑数放到丑数表中，与之对应的index加1。




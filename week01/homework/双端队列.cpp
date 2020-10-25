//
// Created by Administrator on 2020/10/25.
//

class MyCircularDeque {

private:
    //最大容量
    int maxSize;
    //元素个数
    int size;
    //头元素
    int head;
    //尾元素
    int tail;
    int *queue;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        maxSize = k;
        queue = new int[maxSize];
        size = 0;
        head = 0;
        tail = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (size == maxSize) {
            return false;
        }
        queue[head] = value;
        head = --head >= 0 ? head : head + maxSize;
        size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size == maxSize) {
            return false;
        }
        size++;
        tail = (tail + 1) % maxSize;
        queue[tail] = value;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        head = (head + 1) % maxSize;
        size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        tail = --tail >= 0 ? tail : tail + maxSize;
        size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (size == 0) {
            return -1;
        }
        return queue[(head + 1) % maxSize];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (size == 0) {
            return -1;
        }
        return queue[tail];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == maxSize;
    }
};
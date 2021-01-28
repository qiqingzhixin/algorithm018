#include "windows.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef void mySort(int *, int);


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = NULL;
    }

    ListNode(int x) {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode *nodeNext) {
        val = x;
        next = nodeNext;
    }
};

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

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Trie {

private:
    Trie *root[26] = {nullptr};
    bool end = false;

public:
    /** Initialize your data structure here. */

    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *next = this;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (next->root[index] == nullptr) {
                next->root[index] = new Trie();
            }
            next = next->root[index];
        }
        next->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *next = this;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (next->root[index] == nullptr) {
                return false;
            }
            next = next->root[index];
        }
        return next->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *next = this;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (next->root[index] == nullptr) {
                return false;
            }
            next = next->root[index];
        }
        return true;
    }
};

int findCircleNum(vector<vector<int>> &M);

class Node2 {
public:
    Node2 *pre;
    Node2 *next;
    int value;
    int key;

    Node2(int k, int v) {
        key = k;
        value = v;
        pre = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    Node2 *head;
    unordered_map<int, Node2 *> map;
    int cap = 0;
    int count;

public:
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
        head = new Node2(0, 0);
        head->next = head;
        head->pre = head;
    }

    int get(int key) {
        return 0;
    }

    void put(int key, int value) {
        if (count >= cap && head != head->pre) {
            Node2 *p = head->pre;
        }
    }
};


class SolutionCalcEquation {

private:
    int *p;
    double *v;
    unordered_map<string, int> strToInt;


    //初始化
    void init(vector<vector<string>> &equations) {

        int n = 0;

        for (vector<string> item : equations) {
            for (string index : item) {
                if (strToInt.count(index) == 0) {
                    strToInt[index] = n++;
                }
            }
        }

        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            v[i] = 1.0;
        }

        v = new double[n]{0};
    }

    /**
     * 查询
     * @param index
     * @return
     */
    int find(int index) {
        if (p[index] != index) {
            //记录上一个节点的坐标
            int ori = p[index];
            p[index] = find(p[index]);
            v[index] *= v[ori];
        }
        return p[index];
    }

    /**
     * 判断两个下表权值比重
     * @param i
     * @param j
     * @return
     */
    double isConnected(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI == rootJ) {
            return v[i] / v[j];
        } else {
            return -1;
        }
    }

    /**
     * 合并
     * @param i
     * @param j
     */
    void merge(int i, int j, double value) {
        int pi = find(i);
        int pj = find(j);
        if (pi == pj) {
            return;
        }
        p[pi] = pj;
        v[pi] = value * v[j] / v[i];
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        init(equations);

        //合并
        for (int i = 0; i < equations.size(); i++) {
            merge(strToInt[equations[i][0]], strToInt[equations[i][1]], values[i]);
        }
        vector<double> result;
        for (vector<string> item : queries) {
            if (strToInt.count(item[0]) == 0 || strToInt.count(item[1]) == 0) {
                result.push_back(-1);
            } else {
                result.push_back(isConnected(strToInt[item[0]], strToInt[item[1]]));
            }
        }
        return result;
    }
};


class SolutionFindCircleNum {

private:
    int *p;
    int len;
    void init(int n) {
        len = n;
        p = new int[len];
        for (int i = 0; i < len; ++i) {
            p[i] = i;
        }
    }

    int find(int i) {
        while (p[i] != i) {
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }

    void merge(int i, int j) {
        int pI = find(i);
        int pJ = find(j);
        p[i] = j;
    }

    int count() {
        int count = 0;
        for (int i = 0; i < len; ++i) {
            if (p[i] == i) {
                count++;
            }
        }
        return count;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected) {

        init(isConnected.size());
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected[i].size(); ++j) {
                if (isConnected[i][j] == 1) {
                    merge(i, j);
                }
            }
        }
        return count();
    }
};


class MaxNumEdgesToRemove {
private:
    int *alice;
    int *bob;

    int count;

    /**
     * 初始化
     */
    void init(int n) {
        alice = new int[n];
        bob = new int[n];
        for (int i = 0; i < n; ++i) {
            alice[i] = i;
            bob[i] = i;
        }
        count = 0;
    }

    /**
     * 合并
     */
    bool merger(int *p, int n, int m) {
        int pn = find(p, n);
        int pm = find(p, m);
        if (pn != pm) {
            p[pn] = pm;
            return true;
        }
        return false;
    }

    /**
     * 查找
     * @param p
     * @param n
     * @return
     */
    int find(int *p, int n) {
        while (p[n] != n) {
            p[n] = p[p[n]];
            n = p[n];
        }
        return n;
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        init(n);
        for (vector<int> item : edges) {
            if (item[0] == 3) {
                merger(alice, item[1], item[2]);
                if (!merger(bob, item[1], item[2])) {
                    count++;
                }
            }
        }
        for (vector<int> item : edges) {
            if (item[0] == 1) {
                if (!merger(alice, item[1], item[2])) {
                    count++;
                }
            }
            if (item[0] == 2) {
                if (!merger(bob, item[1], item[2])) {
                    count++;
                }
            }
        }
        return count;
    }
};

class GenerateTreesII {
private:
public:
    vector<TreeNode *> generateTrees(int n) {
    }
};



int main() {
    vector<int> result;
    result.push_back(3);
}

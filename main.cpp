#include <iostream>
#include <time.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<math.h>
#include<map>
#include<stack>
#include <sstream>
#include<algorithm>
#include <unordered_map>
#include<queue>
#include<set>
#include<unordered_set>


using namespace std;

typedef void mySort(int *, int);

class ListNode;

void bubble_sort(int *p, int size);

void statistics_time(mySort s, int size, int num, bool out);

void insert_sort(int *p, int size);

void merge_sort(int *p, int size);

void merge_sort_help(int *p, int first, int last);

void merge(int *p, int first, int min, int last);

void quick_sort(int *p, int size);

void quick_sort_help(int *p, int first, int last);

int partition(int *p, int first, int last);

int f(int x, int y, int length);

string convert(string s, int numRows);

int maxLength(vector<vector<char>> &matrix, int i, int j, int temp);

int maximalSquare(vector<vector<char>> &matrix);

int maxArea(vector<int> &height);

int romanToInt(string s);

string longestCommonPrefix(vector<string> &strs);

bool isValid(string s);

char get_char(char a);

string addBinary(string a, string b);

string reverse(string s, int n);

int climbStairs(int n);

int climbStairs_help(int *p, int n);

int mySqrt(int x);

string intToRoman(int num);

string roman_map(int n);

bool isValidSudoku(vector<vector<char>> &board);

void solveSudoku(vector<vector<char>> &board);

bool solveSudokuHelp(int n, vector<vector<char>> &board);

vector<vector<int>> permute(vector<int> &nums);

void permute_help(vector<int> &nums, int n, vector<vector<int>> &result);

vector<string> letterCombinations(string digits);

string digitsToLetter(char digits);

void letterCombinationsHelp(string &digits, string &resultString, int n, vector<string> &result);

vector<vector<int>> threeSum(vector<int> &nums);

vector<vector<int>> fourSum(vector<int> &nums, int target);

int uniquePaths(int m, int n);

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid);

string longestPalindrome(string s);

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

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


int removeDuplicates(vector<int> &nums);


int myAtoi(string s);

vector<int> spiralOrder(vector<vector<int>> &matrix);

ListNode *swapPairs(ListNode *head);

int longestValidParentheses(string s);

bool backspaceCompare(string S, string T);

bool backspaceCompare2(string S, string T);

vector<int> plusOne(vector<int> &digits);

int climbStairs2(int n);

vector<int> twoSum2(vector<int> &nums, int target);

vector<int> twoSum2HashTable(vector<int> &nums, int target);

ListNode *swapPairs2(ListNode *head);

ListNode *swapPairs3(ListNode *head);

ListNode *swapPairs3_2(ListNode *head);

ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2);

ListNode *mergeTwoLists3(ListNode *l1, ListNode *l2);

int removeDuplicates2(vector<int> &nums);


void rotate(vector<int> &nums, int k);

string getHint(string secret, string guess);

void moveZeroes(vector<int> &nums);

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);

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

vector<int> intersect(vector<int> &nums1, vector<int> &nums2);


int trap(vector<int> &height);

vector<int> maxSlidingWindow(vector<int> &nums, int k);

string removeOuterParentheses(string S);

vector<string> fizzBuzz(int n);

int addDigits(int num);

int addDigits2(int num);

bool isAnagram(string s, string t);

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


vector<int> preorder(Node *root);

vector<int> preorderhelp(Node *root, vector<int> &result);


vector<vector<string>> groupAnagrams(vector<string> &strs);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root);

vector<int> inorderTraversalHelp(TreeNode *root, vector<int> &result);

vector<int> preorderTraversal(TreeNode *root);

vector<int> preorderTraversalHelp(TreeNode *root, vector<int> &result);

vector<vector<int>> levelOrder(Node *root);

vector<vector<int>> levelOrder2(Node *root);

vector<vector<int>> levelOrderHelp(vector<Node *> roots, vector<vector<int>> &result);

int nthUglyNumber(int n);

bool isUglyNumber(int n);

int nthUglyNumber2(int n);

vector<int> inorderTraversalMorris(TreeNode *root);

vector<int> topKFrequent(vector<int> &nums, int k);

vector<string> generateParenthesis(int n);

void generateParenthsisHelp(int n, vector<string> &a, vector<string> &b);

void generateParenthsisHelp(int n, string temp, set<string> &a);

void generateParenthsisHelp2(int n, string temp, set<string> &a);

vector<string> generateParenthsisHelp3(int n, string temp, set<string> &a);

string replaceSpace(string s);

int longestUnivaluePath(TreeNode *root);

vector<int> reversePrint(ListNode *head);

void reversePrintHelp(ListNode *head, vector<int> &result);

TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q);

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

bool parentNode(TreeNode *root, TreeNode *p, vector<TreeNode *> &parent);


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);

TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder);

TreeNode *buildTree3(vector<int> &preorder, vector<int> &inorder);

TreeNode *
buildTreeHelp(vector<int> &preorder, vector<int> &inorder, int leftBegin, int leftEnd, int rightBegin, int rightEnd);

void show(vector<int> v);

vector<vector<int>> combine(int n, int k);

vector<vector<int>> combine2(int n, int k);

/**
 *
 * @param result 结果
 * @param temp 中间值
 * @param n 1..n
 * @param k 有几个数
 * @param i 该存放第几个数
 * @param j 存放了最大的数
 */
void combineHelp(vector<vector<int>> &result, vector<int> &temp, int n, int k, int i, int j);

void combine2Help(vector<vector<int>> &result, vector<int> &temp, int n, int k, int i);


vector<vector<int>> permute2(vector<int> &nums);

void permute2Help(vector<vector<int>> &result, vector<int> &nums, int k);

vector<vector<int>> permuteUnique(vector<int> &nums);

void permuteUniqueHelp(vector<vector<int>> &result, vector<int> &nums, int k);

vector<vector<string>> solveNQueens(int n);

void
NQueensHelp(vector<vector<string>> &result, vector<int> &temp, int *lie, int *na, int *pie, int n,
            int k);

bool isTrue(int *lie, int *na, int *pie, int n, int k, int i);

int getKthMagicNumber(int k);

int maxProfit(vector<int> &prices);

ListNode *removeNthFromEnd(ListNode *head, int n);

void rotate(vector<vector<int>> &matrix);

bool lemonadeChange(vector<int> &bills);

int findContentChildren(vector<int> &g, vector<int> &s);

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles);

int numIslands(vector<vector<char>> &grid);

void numIslandsHelp(vector<vector<char>> &grid, int i, int j);

bool isPerfectSquare(int num);

int ladderLengthMax(string beginWord, string endWord, vector<string> &wordList);

int ladderLengthHelp(string beginWord, string endWord, vector<string> &wordList);

int ladderLengthAboutTree(string beginWord, string endWord, vector<string> &wordList);


bool isChangeOne(string &one, string &two);

bool isOK(vector<string> &temp, string &min);

int ladderLength(string beginWord, string endWord, vector<string> &wordList);

vector<vector<char>> updateBoard1(vector<vector<char>> &board, vector<int> &click);

vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click);

int landmineNum(vector<vector<char>> &board, int i, int j);

void updateBoardDfs(vector<vector<char>> &board, int i, int j);

bool canJump(vector<int> &nums, int index);

bool canJump(vector<int> &nums);

bool canJump1(vector<int> &nums);


vector<vector<int>> direction529 = {
        {1,  0},
        {-1, 0},
        {1,  1},
        {-1, 1},
        {1,  -1},
        {-1, -1},
        {0,  -1},
        {0,  1},
};

bool canJump(vector<int> &nums);


int search(vector<int> &nums, int target);

int search(vector<int> &nums, int target, int start, int end);

int searchGW(vector<int> &nums, int target);

bool searchMatrix(vector<vector<int>> &matrix, int target);

int findMin(vector<int> &nums);

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList);

int jumpDT(vector<int> &nums);

int jump(vector<int> &nums);

int jumpHelp(vector<int> &nums, int index, int *minStep);

int majorityElement(vector<int> &nums);

int ladderLength2(string beginWord, string endWord, vector<string> &wordList);

vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string> &wordList);

bool canJump2(vector<int> &nums);

int jump2(vector<int> &nums);

vector<vector<int>> fourSum2(vector<int> &nums, int target);

int robotSim3(vector<int> &commands, vector<vector<int>> &obstacles);

int longestCommonSubsequence(string text1, string text2);

string replaceSpace2(string s);

int maxSubArray(vector<int> &nums);

int minPathSum(vector<vector<int>> &grid);

int coinChangeHelp(vector<int> &coins, int *temp, int amount);

int coinChange(vector<int> &coins, int amount);

int coinChange2(vector<int> &coins, int amount);

int rob(vector<int> &nums);

int rob2(vector<int> &nums);

int rob3(vector<int> &nums);

int robHelp(vector<int> &nums, int index, int *p);

vector<int> preorderN(Node *root);

void preOrderHelp(Node *root, vector<int> &result);

int maxSumSubmatrix(vector<vector<int>> &matrix, int k);

int maxSumSubmatrix2(vector<vector<int>> &matrix, int k);

int maxSumSubmatrix3(vector<vector<int>> &matrix, int k);

int maxSumSubmatrix4(vector<vector<int>> &matrix, int k);

int search_33(vector<int> &nums, int target);

int numDecodings(string s);

int numDecodingsHelp(string s, int index, int *p);

int numDecodings2(string s);

int maximalSquare(vector<vector<char>> &matrix);

int maximalSquare_todo(vector<vector<char>> &matrix);

int maximalSquare_2(vector<vector<char>> &matrix);

int threeMin(int n, int m, int k);

int leastInterval(vector<char> &tasks, int n);

int leastInterval2(vector<char> &tasks, int n);

int countSubstrings(string s);

int countSubstrings2(string s);

int longestValidParentheses(string s);

int longestValidParentheses2(string s);

int longestValidParentheses3(string s);

int longestValidParentheses4(string s);

int minDistance(string word1, string word2);

int minDistance2(string word1, string word2);

bool canCross(vector<int> &stones);

bool canCross2(vector<int> &stones);

bool canCrossHelp(vector<int> &stones, int index, int k);

int maxNums(int *p, int m);

int splitArray(vector<int> &nums, int m);

int splitArray3(vector<int> &nums, int m);

int validIsOK(vector<int> &nums, int m, int n);

int checkRecord(int n);

bool checkRecord(string s);

string minWindow(string s, string t);


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

int findCircleNum2(vector<vector<int>> &M);

void unionParent(int *p, int indexA, int indexB);

void visted(vector<vector<int>> &M, int i);

void solve(vector<vector<char>> &board);

void vistedSolve(vector<vector<char>> &board, int p[4][2], char vistedchar, char changechar, int i, int j);

bool isValidSudoku2(vector<vector<char>> &board);

bool isValidSudoku3(vector<vector<char>> &board);

int climbStairs4(int n);

vector<string> generateParenthesis3(int n);

void generateParenthesisHelp(int n, vector<string> &result, string &item, int left, int right);

int ladderLength3(string beginWord, string endWord, vector<string> &wordList);

bool isEnd(unordered_set<string> &s1, unordered_set<string> &s2);

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2);

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

vector<string> findWords(vector<vector<char>> &board, vector<string> &words);

bool findWordsHelp(vector<vector<char>> &board, int i, int j, string word, int index, int p[4][2]);

int search4(vector<int> &nums, int target);

bool searchMatrix2(vector<vector<int>> &matrix, int target);

int numIslands2(vector<vector<char>> &grid);

int dict[4][2] = {
        {0,  1},
        {1,  0},
        {-1, 0},
        {0,  -1}
};

void visitedIsLands(vector<vector<char>> &grid, int i, int j);

vector<vector<int>> threeSum4(vector<int> &nums);

vector<string> generateParenthesis4(int n);

void generateParenthesisHelp4(vector<string> &result, string item, int n, int left, int right);

int main() {
    vector<string> result = generateParenthesis4(3);
    for (string item:result) {
        cout << item << endl;
    }
    return 0;
}

/**
 * 547.朋友圈
 */
int findCircleNum(vector<vector<int>> &M) {
    
}

/**
 * 22. 生成括号
 * @param n
 * @return
 */
vector<string> generateParenthesis4(int n) {
    vector<string> result;
    string item = "";
    generateParenthesisHelp4(result, item, n, 0, 0);
    return result;
}

void generateParenthesisHelp4(vector<string> &result, string item, int n, int left, int right) {
    if (left > n || right > left) {
        return;
    }
    if (left == n && n == right) {
        result.push_back(item);
        return;
    }
    generateParenthesisHelp4(result, item + ")", n, left, right + 1);
    generateParenthesisHelp4(result, item + "(", n, left + 1, right);
}

/**
 * 15.三数之和
 * @param nums
 * @return
 */
vector<vector<int>> threeSum4(vector<int> &nums) {

    //排序
    sort(nums.begin(), nums.end(), [](int i, int j) { return i < j; });
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        int x = i + 1, y = nums.size() - 1;
        while (x < y) {
            int index = nums[i] + nums[x] + nums[y];
            if (index == 0) {
                result.push_back({nums[i], nums[x], nums[y]});
                while (x + 1 < nums.size() && nums[x] == nums[x + 1]) {
                    x++;
                }
                x++;
                while (y - 1 > 0 && nums[y] == nums[y - 1]) {
                    y--;
                }
                y--;
            } else if (index > 0) {
                while (y - 1 > 0 && nums[y] == nums[y - 1]) {
                    y--;
                }
                y--;
            } else {
                while (x + 1 < nums.size() && nums[x] == nums[x + 1]) {
                    x++;
                }
                x++;
            }
        }
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
    }
    return result;
}

/**
 * 127.单词接龙
 * 双向搜索
 */
int ladderLength3(string beginWord, string endWord, vector<string> &wordList) {
    if (beginWord == endWord) {
        return 1;
    }
    //单词集
    unordered_set<string> wordSet;
    for (int i = 0; i < wordList.size(); ++i) {
        wordSet.insert(wordList[i]);
    }
    if (wordSet.count(endWord) == 0) {
        return 0;
    }
    //开始
    queue<string> beginQueue;
    beginQueue.push(beginWord);
    unordered_set<string> beginVisited;
    beginVisited.insert(beginWord);
    //结束
    queue<string> endQueue;
    endQueue.push(endWord);
    unordered_set<string> endVisited;
    endVisited.insert(endWord);
    int step = 1;
    //正在处理的
    queue<string> *dealQueue = &beginQueue;
    unordered_set<string> *dealVisited = &beginVisited;

    while (!(beginQueue.empty() || endQueue.empty())) {
        if (beginQueue.size() > endQueue.size()) {
            dealQueue = &endQueue;
            dealVisited = &endVisited;
        } else {
            dealQueue = &beginQueue;
            dealVisited = &beginVisited;
        }
        int size = dealQueue->size();
        for (int i = 0; i < size; ++i) {
            string item = dealQueue->front();
            dealQueue->pop();
            for (int j = 0; j < item.size(); ++j) {
                char c = item[j];
                for (int k = 0; k < 26; ++k) {
                    item[j] = 'a' + k;
                    if (wordSet.count(item) == 1 && dealVisited->count(item) == 0) {
                        dealQueue->push(item);
                        dealVisited->insert(item);
                    }
                }
                item[j] = c;
            }
        }
        step++;
        for (string item:beginVisited) {
            if (endVisited.count(item) == 1) {
                return step;
            }
        }
    }
    return 0;
}

/**
 * 53.最大子序列和
 * @param nums
 * @return
 */
int maxSubArray2(vector<int> &nums) {
    int sum = 0;
    int max = INT32_MIN;
    for (int item:nums) {
        if (sum >= 0) {
            sum += item;
            if (sum > max) {
                max = sum;
            }
        } else {
            sum = 0;
        }
    }
    return max;
}

/**
 * 200. 岛屿数量
 * @param grid
 * @return
 */
int numIslands2(vector<vector<char>> &grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '1') {
                count++;
                visitedIsLands(grid, i, j);
            }
        }
    }
    return count;
}

void visitedIsLands(vector<vector<char>> &grid, int i, int j) {
    if (i >= grid.size() || i < 0 || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    for (int k = 0; k < 4; ++k) {
        visitedIsLands(grid, i + dict[k][0], j + dict[k][1]);
    }
}


bool searchMatrix2(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return false;
    }
    int left = 0;
    int right = matrix.size() - 1;
    int mid = left;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (matrix[mid][0] == target) {
            return true;
        } else if (matrix[mid][0] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    mid -= (matrix[mid][0] > target ? 1 : 0);
    if (mid < 0) {
        return false;
    }
    left = 0;
    right = matrix[mid].size() - 1;
    int midY;
    while (left <= right) {
        midY = (left + right) >> 1;
        if (matrix[mid][midY] == target) {
            return true;
        } else if (matrix[mid][midY] > target) {
            right = midY - 1;
        } else {
            left = midY + 1;
        }
    }
    return false;
}

/**
 * 33. 搜索旋转数组
 * @param nums
 * @param target
 * @return
 */
int search4(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1, n = right, mid;
    while (left <= right) {
        mid = (left + right) >> 1;
        //找到了
        if (nums[mid] == target) {
            return mid;
        }
        if ((nums[mid] >= nums[0] && target >= nums[0]) || (nums[mid] <= nums[n] && target <= nums[n])) {
            //同侧
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            //异侧
            if (nums[mid] > target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

/**
 * 212 单词搜索II
 * @param board
 * @param words
 * @return
 */
vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    set<string> result;
    int p[4][2] = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            for (int k = 0; k < words.size(); ++k) {
                if (board[i][j] == words[k][0]) {
                    if (findWordsHelp(board, i, j, words[k], 0, p)) {
                        result.insert(words[k]);
                    }
                }
            }
        }
    }
    vector<string> re(result.begin(), result.end());
    return re;
}

bool findWordsHelp(vector<vector<char>> &board, int i, int j, string word, int index, int p[4][2]) {
    if (word.size() == index) {
        return true;
    }
    if (i >= board.size() || j >= board[i].size()) {
        return false;
    }
    if (board[i][j] == word[index]) {
        board[i][j] = '0';
        bool flag = false;
        for (int k = 0; k < 4; ++k) {
            if (findWordsHelp(board, i + p[k][0], j + p[k][1], word, index + 1, p)) {
                board[i][j] = word[index];
                return true;
            }
        }
        board[i][j] = word[index];
    }
    return false;
}

/**
 *
 * 2,2,2,1,4,3,3,9,6,7,19
 * 1122.数组的相对排序
 * @param arr1
 * @param arr2
 * @return
 */
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_set<int> set;
    unordered_map<int, int> map;
    vector<int> other;
    for (int i = 0; i < arr2.size(); ++i) {
        set.insert(arr2[i]);
    }
    for (int i = 0; i < arr1.size(); ++i) {
        if (set.count(arr1[i])) {
            if (map.count(arr1[i])) {
                map[arr1[i]]++;
            } else {
                map[arr1[i]] = 1;
            }
        } else {
            other.push_back(arr1[i]);
        }
    }
    sort(other.begin(), other.end(), [](int i, int j) { return i < j; });
    vector<int> result;
    for (int j = 0; j < arr2.size(); ++j) {
        if (map.count(arr2[j])) {
            for (int i = 0; i < map[arr2[j]]; ++i) {
                result.push_back(arr2[j]);
            }
        }
    }
    result.insert(result.end(), other.begin(), other.end());
    return result;
}

/**
 * 190. 颠倒二进制位
 */
uint32_t reverseBits(uint32_t n) {
    uint32_t reverse = 0;
    for (int i = 0; i < 32; ++i) {
        reverse = (reverse << 1) + (n & 1);
        n = n >> 1;
    }
    return reverse;
}

/**
 * 231. 2的幂
 * @param n
 * @return
 */
bool isPowerOfTwo(int n) {
    return !(n & (n - 1));
}

/**
 * 191. 位1 个数
 * @param n
 * @return
 */
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

/**
 * 312.戳气球 todo
 * @param nums
 * @return
 */
int maxCoins(vector<int> &nums) {

    return 0;
}


bool isEnd(unordered_set<string> &s1, unordered_set<string> &s2) {
    for (string s:s1) {
        if (s2.count(s) != 0) {
            return true;
        }
    }
    return false;
}

/**
 * 22.生成括号
 * @param n
 * @return
 */
vector<string> generateParenthesis3(int n) {
    vector<string> result;
    string item = "";
    generateParenthesisHelp(n, result, item, 0, 0);
    return result;
}

void generateParenthesisHelp(int n, vector<string> &result, string &item, int left, int right) {
    if (left > n || left < right) {
        return;
    }
    if (n == right) {
        result.push_back(item);
        return;
    }
    item.push_back('(');
    generateParenthesisHelp(n, result, item, left + 1, right);
    item.pop_back();
    item.push_back(')');
    generateParenthesisHelp(n, result, item, left, right + 1);
    item.pop_back();
}


/**
 * 爬楼梯
 * f(n)=f(n-1)+f(n-2);
 * @param n
 * @return
 */
int climbStairs4(int n) {
    long pref = 1;
    long next = 2;
    for (int i = 1; i < n; ++i) {
        next = pref + next;
        pref = next - pref;
    }
    return pref;
}

/**
 * 使用数组
 * @param board
 * @return
 */
bool isValidSudoku3(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
        int hen[9]{0};
        int lie[9]{0};
        int zh[9]{0};
        for (int j = 0; j < 9; ++j) {
            //横
            if (board[i][j] != '.') {
                if (hen[board[i][j] - '1'] != 0) {
                    return false;
                } else {
                    hen[board[i][j] - '1']++;
                }
            }
            //竖
            if (board[j][i] != '.') {
                if (lie[board[j][i] - '1'] != 0) {
                    return false;
                } else {
                    lie[board[j][i] - '1']++;
                }
            }
            //正方形
            int tempI = (i / 3) * 3 + j / 3;
            int tempJ = (i % 3) * 3 + j % 3;
            if (board[tempI][tempJ] != '.') {
                if (zh[board[tempI][tempJ] - '1'] != 0) {
                    return false;
                } else {
                    zh[board[tempI][tempJ] - '1']++;
                }
            }
        }
    }
    return true;
}

/**
 * 有效的数独
 * @param board
 * @return
 */
bool isValidSudoku2(vector<vector<char>> &board) {
    unordered_set<char> hen;
    unordered_set<char> lie;
    unordered_set<char> zh;
    for (int i = 0; i < 9; ++i) {
        hen.clear();
        lie.clear();
        zh.clear();
        for (int j = 0; j < 9; ++j) {
            //横
            if (board[i][j] != '.') {
                if (hen.count(board[i][j]) != 0) {
                    return false;
                } else {
                    hen.insert(board[i][j]);
                }
            }
            //竖
            if (board[j][i] != '.') {
                if (lie.count(board[j][i]) != 0) {
                    return false;
                } else {
                    lie.insert(board[j][i]);
                }
            }
            //正方形
            int tempI = (i / 3) * 3 + j / 3;
            int tempJ = (i % 3) * 3 + j % 3;
            if (board[tempI][tempJ] != '.') {
                if (zh.count(board[tempI][tempJ]) != 0) {
                    return false;
                } else {
                    zh.insert(board[tempI][tempJ]);
                }
            }
        }
    }
    return true;
}

/**
 * 130. 被围绕的区域
 * 使用深度遍历，遍历四周的O，改为Q,然后将剩余的O改为X，最后将Q改为O 时间复杂度n^2
 * @param board
 */
void solve(vector<vector<char>> &board) {
    int n = board.size();
    if (n == 0) {
        return;
    }
    int m = board[0].size();
    if (m == 0) {
        return;
    }
    int dis[4][2] = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };
    //将四周的变成Q
    for (int i = 0; i < n; ++i) {
        if (board[i][0] == 'O') {
            vistedSolve(board, dis, 'O', 'Q', i, 0);
        }
        if (board[i][m - 1] == 'O') {
            vistedSolve(board, dis, 'O', 'Q', i, m - 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (board[0][i] == 'O') {
            vistedSolve(board, dis, 'O', 'Q', 0, i);
        }
        if (board[n - 1][i] == 'O') {
            vistedSolve(board, dis, 'O', 'Q', n - 1, i);
        }
    }
    // 将中间的O改成X
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (board[i][j] == 'O') {
                vistedSolve(board, dis, 'O', 'X', i, j);
            }
        }
    }

    //将Q变回O
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'Q') {
                vistedSolve(board, dis, 'Q', 'O', i, j);
            }
        }
    }
}

/**
 *
 * @param board
 * @param p 方向
 * @param vistedchar 要拜访的字符
 * @param changechar 改成的字符
 * @param i
 * @param j
 */
void vistedSolve(vector<vector<char>> &board, int p[4][2], char vistedchar, char changechar, int i, int j) {
    board[i][j] = changechar;
    int tempi;
    int tempj;
    for (int k = 0; k < 4; ++k) {
        tempi = i + p[k][0];
        tempj = j + p[k][1];
        if (tempi >= 0 && tempi < board.size() && tempj >= 0 && tempj < board[0].size() &&
            board[tempi][tempj] == vistedchar) {
            vistedSolve(board, p, vistedchar, changechar, tempi, tempj);
        }
    }
}

/**
 * 深搜
 * @param M
 * @return
 */
int findCircleNum2(vector<vector<int>> &M) {
    int count = 0;
    int n = M.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (M[i][j] == 1) {
                count++;
                M[i][j] = 0;
                visted(M, j);
            }
        }
    }
    return count;
}

void visted(vector<vector<int>> &M, int i) {
    for (int j = 0; j < M.size(); ++j) {
        if (M[i][j] == 1) {
            M[i][j] = 0;
            visted(M, j);
        }
    }
}

/**
 * 547.朋友圈
 * 并查集的方式
 * @param M
 * @return
 */
int findCircleNum(vector<vector<int>> &M) {
    int n = M.size();
    int *p = new int[n];
    for (int k = 0; k < n; ++k) {
        p[k] = k;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (M[i][j] == 1) {
                unionParent(p, i, j);
                for (int i = 0; i < n; ++i) {
                    cout << p[i] << '\t';
                }
                cout << endl;
            }
        }
    }
    int count = 0;
    for (int l = 0; l < n; ++l) {
        if (p[l] == l) {
            count++;
        }
    }
    return count;
}

/**
 * 找爸爸
 * @param p
 * @param length
 * @param index
 * @return
 */
int findParent(int *p, int index) {
    while (p[index] != index) {
        index = p[index];
    }
    return index;
}

void unionParent(int *p, int indexA, int indexB) {
    int aParent = findParent(p, indexA);
    int bParent = findParent(p, indexB);
    if (aParent != bParent) {
        p[bParent] = aParent;
    }
}

/**
 * 76.最小覆盖子串
 * @param s
 * @param t
 * @return
 */
string minWindow(string s, string t) {
    if (t == "" || s == "") {
        return "";
    }
    //汉明距离
    int distance = t.size();
    unordered_map<char, int> sMap, tMap;
    for (int i = 0; i < t.size(); ++i) {
        if (tMap.count(t[i]) == 0) {
            tMap[t[i]] = 1;
            sMap[t[i]] = 0;
        } else {
            tMap[t[i]]++;
        }
    }
    int left = 0, right = 0, min = s.size() + 1;
    int minLeft = 0;
    while (right < s.size()) {
        if (tMap.count(s[right]) != 0) {
            sMap[s[right]]++;
            //如果有且没有超过汉明距离-1
            if (sMap[s[right]] <= tMap[s[right]]) {
                distance--;
                //没有了汉明距离
                while (distance == 0) {
                    if (min > (right - left + 1)) {
                        min = right - left + 1;
                        minLeft = left;
                    }
                    if (tMap.count(s[left]) != 0) {
                        sMap[s[left]]--;
                        //如果窗口的字符不满足需要的汉明距离+1
                        if (sMap[s[left]] < tMap[s[left]]) {
                            distance++;
                        }
                    }
                    //指向下一个
                    left++;
                }
            }
        }
        right++;
    }
    //说明没有匹配上
    if (min == s.size() + 1) {
        return "";
    }
    return s.substr(minLeft, min);
}

/**
 * 552.学生出勤记录II
 * @param n
 * @return
 */
int checkRecord(int n) {
    int M = 1000000007;
    long **p = new long *[3];
    for (int i = 0; i < 3; ++i) {
        p[i] = new long[2]{0};
    }
    p[0][0] = 1;
    p[1][0] = 1;
    p[0][1] = 1;
    for (int j = 1; j < n; ++j) {
        //p[0][0]
        long temp1 = (p[0][0] + p[1][0] + p[2][0]) % M;
        //p[0][1]
        long temp2 = (p[0][1] + p[1][1] + p[2][1] + p[1][0] + p[2][0] + p[0][0]) % M;
        p[2][1] = p[1][1];
        p[1][1] = p[0][1];
        p[2][0] = p[1][0];
        p[1][0] = p[0][0];
        p[0][0] = temp1;
        p[0][1] = temp2;
    }
    long sum = 0;
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 2; ++i) {
            sum = (sum + p[k][i]) % M;
        }
    }
    return (int) sum;
}


/**
 * 551.学生出勤记录I
 * 'A' : Absent，缺勤
 * 'L' : Late，迟到
 * 'P' : Present，到场
 * @param s
 * @return
 */
bool checkRecord(string s) {
    int aNum = 0, lNum = 0;
    for (int i = 0; i < s.size(); ++i) {

        if (s[i] == 'A') {
            aNum++;
            if (aNum > 1) {
                return false;
            }
        }
        if (s[i] == 'L') {
            lNum++;
            if (lNum > 2) {
                return true;
            }
        } else {
            lNum = 0;
        }
    }
    return true;
}

/**
 * 首先能确定最大值的取值范围 在[max(nums),sum[nums]] 范围
 * 如果我在这个里面取一个值 l，然后让每一个子段不能大于这个值，看看能分成k，如果k>m ,说明l取小了，如果k<m说明取大了，k=m 有可能取大了。 知道所有数试一遍
 * 这里可以使用二分查找来加速搜索。
 * @param nums
 * @param m
 * @return
 */
int splitArray3(vector<int> &nums, int m) {
    //数组中最大的值，数组之和
    int left = nums[0], right = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (left < nums[i]) {
            left = nums[i];
        }
        right += nums[i];
    }
    //初始化最小值
    int min = right;
    while (left <= right) {
        //取中间的值
        int mid = (left + right) / 2;
        int validNum = validIsOK(nums, m, mid);
        if (validNum == 1) {
            if (min > mid) {
                min = mid;
            }
            right = mid - 1;
        } else if (validNum == -1) {
            left = mid + 1;
        }
    }
    return min;
}

/**
 *
 * @param nums
 * @param m 要分成分成多少段
 * @param n 每一段的最大值
 * @return -1 代表n取小了，0 有可能合适，1 n取大了
 */
int validIsOK(vector<int> &nums, int m, int n) {
    //分了多少段
    int count = 1;
    int temp = 0;
    for (int i = 0; i < nums.size(); ++i) {
        temp += nums[i];
        //超了
        if (temp > n) {
            temp = nums[i];
            count++;
        }
    }
    if (count > m) {
        return -1;
    }
    return 1;
}

int splitArray2(vector<int> &nums, int m) {
    int n = nums.size();
    vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
    vector<long long> sub(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sub[i + 1] = sub[i] + nums[i];
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, m); j++) {
            for (int k = 0; k < i; k++) {
                f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
            }
        }
    }
    return (int) f[n][m];

}

/**
 *
 * 分割数组的最大值
 * 使用动态规划
 * @param nums
 * @param m
 * @return
 */
int splitArray(vector<int> &nums, int m) {
    if (nums.size() == 0 && m == 0) {
        return 0;
    }
    // 0代表偶数，1代表奇数,2 代表0-i所有数之和
    int **p = new int *[3];
    for (int i = 0; i < 3; ++i) {
        p[i] = new int[nums.size()];
    }
    p[1][0] = nums[0];
    //方便计算任意一段的数值
    p[2][0] = nums[0];
    p[0][0] = INT32_MAX;
    //初始化 也代表分成1段的情况 段的最大值中的最小值
    for (int i = 1; i < nums.size(); ++i) {
        p[1][i] = nums[i] + p[1][i - 1];
        p[2][i] = nums[i] + p[2][i - 1];
        p[0][i] = INT32_MAX;
    }
    //m:代表分成m段
    for (int i = 2; i <= m; ++i) {
        //最大坐标为;
        for (int n = i - 1; n < nums.size(); ++n) {
            // 看成 前j个数分成i-1段 最后一段的取值为j+1,nums.size();
            for (int j = i - 2; j < n; ++j) {
                //这个状态 第一个数 = 之前的状状态值（肯定大于现在的状态 因为相同的数，分的份数变多，所以分的份数大的最大值一定小于等于分的份数少的最大值),
                // 上一个状态 分成i-1 段中包含了j-1 个数，最后一段 包含了 nums.size()-j个数
                p[i % 2][n] = min(p[i % 2][n], max(p[(i - 1) % 2][j], p[2][n] - p[2][j]));
            }
        }
    }
    return p[m % 2][nums.size() - 1];
}


int maxNums(int *p, int m) {
    int max = INT32_MIN;
    for (int i = 0; i < m; ++i) {
        if (p[i] > max) {
            max = p[i];
        }
    }
    return max;
}

/**
 * 采用记忆集的方式
 * vector<int> *p=new vector<int>[size]
 * p[i] 记录跳到i可以跳的步数
 * @param stones
 * @return
 */
bool canCross2(vector<int> &stones) {
    auto p = new unordered_set<int>[stones.size()];
    //方便快速定位坐标
    unordered_map<int, int> stones_map;
    for (int j = 0; j < stones.size(); ++j) {
        stones_map[stones[j]] = j;
    }
    p[0].insert(1);
    for (int i = 0; i < stones.size(); ++i) {
        for (int x:p[i]) {
            //跳到第几个单元
            int next = stones[i] + x;
            if (next == stones[stones.size() - 1]) {
                return true;
            }
            if (stones_map.count(next) > 0) {
                //找到了
                int nextIndex = stones_map[next];
                if (x - 1 > 0) {
                    p[nextIndex].insert(x - 1);
                }
                p[nextIndex].insert(x);
                p[nextIndex].insert(x + 1);
            }
        }
    }
    return false;
}

/**
 * 403 青蛙过河
 * p[i][j]=k 第i个石子第j种跳发
 * [0,1,3,5,6,8,12,17]
 * @param stones
 * @return
 */
bool canCross(vector<int> &stones) {
    return canCrossHelp(stones, 0, 1);
}

/**
 * 在 第index位置跳k步
 * @param stones
 * @param index 在那个坐标
 * @param k 要跳多少步
 * @return
 */
bool canCrossHelp(vector<int> &stones, int index, int k) {
    if (k <= 0) {
        return false;
    }
    // 跳到下一个数字
    int next = stones[index] + k;
    if (next == stones[stones.size() - 1]) {
        //跳到了终点
        return true;
    } else if (next > stones[stones.size() - 1]) {
        //跳过了
        return false;
    }
    //最左边
    int left = index + 1;
    int right = stones.size() - 1;
    int mid;
    bool flag = false;
    //二分查找
    while (left <= right) {
        mid = (left + right) / 2;
        if (stones[mid] == next) {
            //找到了
            flag = canCrossHelp(stones, mid, k - 1) || canCrossHelp(stones, mid, k) ||
                   canCrossHelp(stones, mid, k + 1);
            //有真的
            if (flag) {
                return flag;
            } else {
                break;
            }
        } else if (stones[mid] > next) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    //没有真的
    return false;
}


/**
 * 思想不变只不过使用二维数组有点浪费，可以优化成一维数组
 * 这是一位我们只能用到相邻的数据，不会用到其他位置的数据
 * x x
 * x o ->
 *
 * xt xt-1 -> xt 0t
 * 要把xt-1 保存在 x0中
 * @param word1
 * @param word2
 * @return
 */
int minDistance2(string word1, string word2) {
    if (word1.size() == 0 || word2.size() == 0) {
        return word2.size() + word1.size();
    }
    int len2 = word2.size();
    int *p = new int[len2 + 1];
    //初始化
    for (int i = 0; i < len2 + 1; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < word1.size(); ++i) {
        //存放上一个状态
        p[0] = i;
        for (int j = 1; j < len2 + 1; ++j) {
            int min = p[0];
            if (word1[i] != word2[j - 1]) {
                min = p[0] + 1;
            }
            p[0] = p[j];
            if (min > p[j] + 1) {
                min = p[j] + 1;
            }
            if (min > p[j - 1] + 1) {
                min = p[j - 1] + 1;
            }
            p[j] = min;
        }
    }
    return p[len2];
}

/**
 * 72.编辑距离
 * 由他人分析可得
 * 操作可以有
 * word1 插入一个字符
 * word2 插入一个字符
 * word1 替换一个字符
 * p[word1.size+1][word2.size+1]={0};
 * 最后一个字母相同
 *  p[i][j]=min(p[i-1][j]+1,p[i][j-1]+1,p[i-1][j-1])
 * 最后一个字母不同
 *  p[i][j]=min(p[i-1][j]+1,p[i][j-1]+1,p[i-1][j-1]+1)=1+min(p[i-1][j],p[i][j-1],p[ji-1][j-1]);
 *
 *
 * @param word1
 * @param word2
 * @return
 */

int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    int **p = new int *[len1 + 1];
    for (int i = 0; i <= len1; ++i) {
        p[i] = new int[len2 + 1];
    }
    //初始化
    for (int j = 0; j <= len1; ++j) {
        p[j][0] = j;
    }
    for (int j = 1; j <= len2; ++j) {
        p[0][j] = j;
    }
    //进行dp
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                p[i][j] = p[i - 1][j] + 1;
                if (p[i][j - 1] + 1 < p[i][j]) {
                    p[i][j] = p[i][j - 1] + 1;
                }
                if (p[i][j] > p[i - 1][j - 1]) {
                    p[i][j] = p[i - 1][j - 1];
                }
            } else {
                p[i][j] = p[i - 1][j];
                if (p[i][j] > p[i][j - 1]) {
                    p[i][j] = p[i][j - 1];
                }
                if (p[i][j] > p[i - 1][j - 1]) {
                    p[i][j] = p[i - 1][j - 1];
                }
                p[i][j] += 1;
            }
        }
    }
    return p[len1][len2];
}

/**
 * 计数左右括号的数量
 * 只要有左括号，来个右括号就能匹配
 * 当相等就有可能是最大的
 * 当右括号大于左括号则说明，新的一轮开始
 *
 * 为了防止左括号过多无法得到相等情况，反着再来一遍
 * @param s
 * @return
 */
int longestValidParentheses4(string s) {
    int max = 0, left = 0, right = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max = left * 2;
        } else if (left < right) {
            left = 0;
            right = 0;
        }
    }

    for (int j = s.size() - 1; j >= 0; --j) {
        if (s[j] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max = left * 2;
        } else if (right < left) {
            left = 0;
            right = 0;
        }
    }
    return max;
}


/**
 * 使用栈的思想
 *
 * 所有的'('位置，如果遇到')'栈顶位置就是与之匹配的'('字符，就能计算出有效括号的长度
 * @param s
 * @return
 */

int longestValidParentheses3(string s) {
    int max = 0;
    stack<int> stack;
    //存放初始位置
    stack.push(-1);
    for (int i = 0; i < s.size(); ++i) {

        if (s[i] == '(') {
            stack.push(i);
        } else {
            stack.pop();
            if (stack.empty()) {
                stack.push(i);
            } else {
                int temp = i - stack.top();
                max = (temp > max ? temp : max);
            }
        }
    }
    return max;
}

/**
 * 最长有效括号 动态规划
 * if p[i]==')' &&p[i-1]=='(' 则 p[i]=p[i-2]+2;
 * if p[i]==')' &&p[i-1]==')' && s[i-p[i-1]-1]=='(' 则 p[i]=p[i-1]+2+p[i-p[i-1]-2]
 *
 * @param s
 * @return
 */
int longestValidParentheses2(string s) {
    if (s.size() <= 1) {
        return 0;
    }
    //存放最大值
    int max = 0;
    int *p = new int[s.size()]{0};
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                p[i] = (i - 2 >= 0 ? p[i - 2] : 0) + 2;
            } else if (i - p[i - 1] - 1 >= 0 && s[i - 1] == ')' && s[i - p[i - 1] - 1] == '(') {
                p[i] = p[i - 1] + 2 + (i - p[i - 1] - 2 >= 0 ? p[i - p[i - 1] - 2] : 0);
            }
            max = p[i] > max ? p[i] : max;
        }
    }
    return max;
}


/**
 * 最长有效括号
 * difeite
 * @param s
 * @return
 */
int longestValidParentheses(string s) {
    if (s.size() == 0) {
        return 0;
    }
    int max = 0;
    int leftNum = 0;
    int rightNum = 0;
    bool *flag = new bool[s.size()]{false};
    for (int i = 0; i < s.size();) {
        //数左括号
        for (; s[i] == '(' && i < s.size(); i++) {
            leftNum++;
        }
        //数右括号
        for (; s[i] == ')' && i < s.size(); i++) {
            rightNum++;
        }
        if (leftNum >= rightNum) {
            //左括号大于右括号
            for (int j = i - rightNum * 2; j < i; ++j) {
                flag[j] = true;
            }
        } else {
            //左括号小于右括号
            for (int j = i - rightNum - leftNum; j < i - (rightNum - leftNum); ++j) {
                flag[j] = true;
            }
        }
        leftNum = rightNum = 0;
    }
    int temp = 0;
    //数最长的true
    for (int k = 0; k < s.size(); ++k) {
        cout << flag[k] << '\t';
        if (flag[k]) {
            temp++;
        } else {
            if (temp > max) {
                max = temp;
            }
            temp = 0;
        }
    }
    if (temp > max) {
        max = temp;
    }
    return max;
}

/**
 * Manacher 算法
 * 记录状态
 * @param s
 * @return
 */
int countSubstrings5(string s) {
    string dealS = "$#";
    for (int j = 0; j < s.size(); ++j) {
        dealS = dealS + s[j] + "#";
    }
    dealS = dealS + "!";
    //记录有多少个字串
    int count = 0;
    //记录最右边的回文序列边界
    int maxRight = 0;
    //记录最右边的回文序列边界中心位置
    int maxRightIndex = 0;
    //记录状态的数组
    int *f = new int[dealS.size()]{0};
    for (int i = 1; i < dealS.size() - 1; ++i) {
        if (i <= maxRight) {
            // i关于maxRightIndex 对称坐标
            int j = maxRightIndex * 2 - i;
            //与最右端的最大距离
            int dx = maxRight - i + 1;
            //不能超过最右端
            f[i] = j > dx ? dx : j;
        } else {
            f[i] = 1;
        }
        //中心扩展
        while (dealS[i - f[i]] == dealS[i + f[i]]) {
            f[i]++;
        }
        // 更新数据
        if (i + f[i] - 1 > maxRight) {
            maxRightIndex = i;
            maxRight = f[i] + i - 1;
        }
        // 累加字串数
        count += (f[i] / 2);
    }
    return count;
}

/**
 * 遍历
 * @param s
 * @return
 */
int countSubstrings4(string s) {
    int count = 0;
    int size = s.size();
    int length = s.size() * 2 - 1;
    int l, r;
    for (int i = 0; i < length; ++i) {
        l = i / 2;
        r = (i + 1) / 2;
        while (s[l] == s[r] && l >= 0 && r < size) {
            count++;
            l--;
            r++;
        }
    }
    return count;
}

/**
 * 根据长度来进行dp，这个可以优化内存
 * f(len,index) = true,len=1
 * f(len,index) = s[index]==s[index+1] ,len=2;
 * f(len,index) = s[index]==s[index+len] && f(len-2,index+1) ,len>2
 * @param s
 * @return
 */
int countSubstrings(string s) {
    int length = s.size();
    if (length <= 1) {
        return length;
    }
    int count = length;
    bool **p = new bool *[length];
    for (int j = 0; j < length; ++j) {
        p[j] = new bool[length]{false};
    }
    //len==1
    for (int i = 0; i < length; ++i) {
        p[0][i] = true;
    }
    //len==2
    for (int k = 0; k < length - 1; ++k) {
        if (s[k] == s[k + 1]) {
            p[1][k] = true;
            count++;
        }
    }
    //len > 2
    for (int m = 2; m < length; ++m) {
        for (int l = 0; l < length - m; ++l) {
            if (s[l] == s[l + m] && p[m - 2][l + 1]) {
                p[m][l] = true;
                count++;
            }
        }
    }
    return count++;
}

/**
 * 优化内存
 * @param s
 * @return
 */
int countSubstrings2(string s) {
    int length = s.size();
    if (length <= 1) {
        return length;
    }
    int count = length;
    bool **p = new bool *[2];
    p[0] = new bool[length];
    p[1] = new bool[length];
    //len=1;
    for (int i = 0; i < length; ++i) {
        p[0][i] = true;
    }
    //len=2
    for (int i = 0; i < length - 1; ++i) {
        count += (p[1][i] = s[i] == s[i + 1]);
    }
    for (int i = 2; i < length; ++i) {
        for (int j = 0; j < length - i; ++j) {
            count += (p[i % 2][j] = (s[j] == s[j + i] && p[i % 2][j + 1]));
        }
    }
    return count;
}

/**
 *
 * f(x,y)=true x=y;
 * f(x,y)= s[x]==s[y], y-x=1;
 * f(x,y)= f(x+1,y-1)&& s[x]==s[y] (y-x>1);
 * @param s
 * @return
 */
int countSubstrings3(string s) {
    int length = s.size();
    if (length <= 1) {
        return length;
    }
    int count = length;
    bool **p = new bool *[length];
    for (int j = 0; j < length; ++j) {
        p[j] = new bool[length]{false};
    }
    for (int i = 0; i < length; ++i) {
        p[0][i] = true;
    }
    return 0;
}

/**
 * 设至少有一种任务A出现次数最多，最大出现次数记为cnt_max
    设出现次数与cnt_max相等的任务有equal_cnt_max个
    1、有cnt_max个A任务，共有（cnt_max-1）个间隔，每个间隔题目要求插入n个不同的任务，凑不够n个不同任务我们用“待命”来填充。
    2、最后一个A后面可能还有其他任务，此时的其他任务只能是出现次数等于cnt_max的任务，不然它早就全部用来填充（（cnt_max-1））个间隔了(每个间隔需填充一个)
    3、特殊情况是n=0，则题目求出来的答案应该是任务的总数，即代码中的task.size();
    4、答案要包括任务A的个数，所以答案 ans = max((cnt_max-1)*n + cnt_max + equal_cnt_max,tasks.size())
 * @param tasks
 * @param n
 * @return
 */

int leastInterval2(vector<char> &tasks, int n) {
    int *p = new int[26]{0};
    for (int i = 0; i < tasks.size(); ++i) {
        p[tasks[i] - 'A']++;
    }
    //排序
    sort(p, p + 26, [](int &x, int &y) { return x > y; });
    int index = 1;
    while (index < 26 && p[0] == p[index]) {
        index++;
    }
    int m1 = index + (p[0] - 1) * (n + 1);
    return m1 > tasks.size() ? m1 : tasks.size();
}


//int leastInterval2(vector<char> &tasks, int n){
//    int len=tasks.size();
//    vector<int> vec(26);
//    for(char c:tasks) ++vec[c-'A'];
//    sort(vec.begin(),vec.end(),[](int& x,int&y){return x>y;});
//    int cnt=1;
//    while(cnt<vec.size()&&vec[cnt]==vec[0]) cnt++;
//    return max(len,cnt+(n+1)*(vec[0]-1) );
//}

/**
 * 621.任务调度器
 * f(n)=f(n-1)+task(n);
 * @param tasks
 * @param n
 * @return
 */
int leastInterval(vector<char> &tasks, int n) {
    int *taskMap = new int[26]{0};
    int time = 0;
    for (int i = 0; i < tasks.size(); ++i) {
        taskMap[tasks[i] - 'A']++;
    }
    priority_queue<int> queue;
    for (int i = 0; i < 26; ++i) {
        if (taskMap[i] > 0) {
            queue.push(taskMap[i]);
        }
    }
    while (!queue.empty()) {
        vector<int> temp;
        for (int i = 0; i <= n; ++i) {
            if (queue.top() > 1) {
                temp.push_back(queue.top() - 1);
            }
            queue.pop();
            time++;
            if (queue.empty()) {
                if (temp.size() != 0) {
                    time += (n - i);
                }
                break;
            }
        }
        for (int j = 0; j < temp.size(); ++j) {
            queue.push(temp[j]);
        }
    }
    return time;
}


/**
 * 使用动态规划去找最大的正方形面积
 * @param matrix
 * @return
 */
int maximalSquare_2(vector<vector<char>> &matrix) {
    int max = 0;
    int length = matrix.size();
    if (length == 0) {
        return max;
    }
    int weight = matrix[0].size();
    if (weight == 0) {
        return max;
    }
    int *p = new int[weight]{0};
    for (int i = 0; i < length; ++i) {
        int temp = p[0];
        if (matrix[i][0] == '1') {
            p[0] = 1;
            if (p[0] > max) {
                max = 1;
            }
        } else {
            temp = p[0];
            p[0] = 0;
        }
        for (int j = 1; j < weight; ++j) {
            if (matrix[i][j] == '1') {
                int min = threeMin(p[j], p[j - 1], temp);
                temp = p[j];
                p[j] = min + 1;
                if (p[j] > max) {
                    max = p[j];
                }
            } else {
                temp = p[j];
                p[j] = 0;
            }
        }

    }
    return max * max;
}

int threeMin(int n, int m, int k) {
    int min = n;
    if (min > m) {
        min = m;
    }
    if (min > k) {
        min = k;
    }
    return min;
}

/**
 * 221.最大的正方形
 * @param matrix
 * @return
 */
int maximalSquare_todo(vector<vector<char>> &matrix) {
    int max = 0;
    int length = matrix.size();
    int weight = matrix[0].size();
    for (int i = 0; i < length; ++i) {
        bool *p = new bool[weight]{false};
        for (int len = 0; i + len < length; ++len) {
            for (int j = 0; j < weight; ++j) {
                if (p[j] == false && matrix[i + len][j] == '0') {
                    p[j] = true;
                }
            }
            int w = 0;
            for (int k = 0; k < weight; ++k) {
                if (p[k] == false) {
                    w++;
                    if (w == len + 1 && len + 1 > max) {
                        max = len + 1;
                        break;
                    }
                } else {
                    w = 0;
                }
            }
        }
    }
    return max * max;
}

/**
 * 91.解码方法
 * @param s
 * @return
 */
int numDecodings(string s) {
    if (s.size() == 0) {
        return 0;
    }
    int *p = new int[s.size() + 1]{0};
    return numDecodingsHelp(s, 0, p);
}

int numDecodingsHelp(string s, int index, int *p) {
    //index=s.length()
    if (p[index] != 0) {
        return p[index];
    }
    if (s[index] == '0') {
        return 0;
    }
    if (index >= s.size() - 1) {
        p[index] = 1;
        return 1;
    }
    // 1 :1-9 2: 1-6
    if (s[index] == '1' ||
        (s[index] == '2' && s[index + 1] >= '0' && s[index + 1] <= '6')) {
        p[index] = numDecodingsHelp(s, index + 1, p) + numDecodingsHelp(s, index + 2, p);
        return p[index];
    }
    p[index] = numDecodingsHelp(s, index + 1, p);
    return p[index];
}

/**
 * 根据斐波那契数列改造的
 * @param s
 * @return
 */
int numDecodings2(string s) {
    if (s.size() == 0 || s[0] == '0') {
        return 0;
    }
    int first = 1;
    int next = 1;
    for (int i = 1; i < s.size(); ++i) {
        int temp = 0;
        //
        if (s[i] != '0') {
            temp += next;
        }
        if ((s[i - 1] == '1' && s[i] != '0') || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
            temp += first;
        }
        if (s[i - 1] <= '2' && s[i] == '0') {
            temp += first;
        }
        if (s[i - 1] == '0' && s[i] == '0') {
            return 0;
        }
        first = next;
        next = temp;
    }
    return next;
}

/**
 * 33. 搜索旋转排序数组
 * @param nums
 * @param target
 * @return
 */
int search_33(vector<int> &nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }
    if (nums.size() == 1) {
        return nums[0] == target ? 0 : -1;
    }
//    if(nums)
    return 0;
}

/**
 * 363 给定一个非空二维矩阵 matrix 和一个整数 k，找到这个矩阵内部不大于 k 的最大矩形和
 * 当宽度和高度都为1
 *
 * f(iStart,jStart,iEnd,jEnd)=f(iStart,jStart,iEnd-1,jEnd-i)+f(iEnd-1,jStart,iEnd,jEnd-1)+f(iStart,jEnd-1,iEnd-1,jEnd)+f(iEnd,jEnd,iEnd,jEnd)
 * @param matrix
 * @param k
 * @return
 */
int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int length = matrix.size();
    int weight = matrix[0].size();
    int max = INT32_MIN;
    int ****p = new int ***[length];
    for (int i = 0; i < length; ++i) {
        p[i] = new int **[weight];
        for (int j = 0; j < weight; ++j) {
            p[i][j] = new int *[length];
            for (int l = 0; l < length; ++l) {
                p[i][j][l] = new int[weight];
            }
        }
    }
    //宽度
    for (int iLength = 1; iLength <= length; ++iLength) {
        for (int jWeight = 1; jWeight <= weight; ++jWeight) {
            for (int i = 0; i <= length - iLength; ++i) {
                for (int j = 0; j <= weight - jWeight; ++j) {
                    int iEnd = i + iLength - 1;
                    int jEnd = j + jWeight - 1;
                    if (i == iEnd && j == jEnd) {
                        // 一个元素
                        p[i][j][i][j] = matrix[i][j];
                    } else if (i == iEnd) {
                        //一行元素
                        p[i][j][i][jEnd] = p[i][j][i][jEnd - 1] + p[i][jEnd][i][jEnd];
                    } else if (j == jEnd) {
                        //一列元素
                        p[i][j][iEnd][j] = p[i][j][iEnd - 1][j] + p[iEnd][j][iEnd][j];
                    } else {
                        //多行多列
                        p[i][j][iEnd][jEnd] = p[i][j][iEnd - 1][jEnd - 1] + p[iEnd][j][iEnd][jEnd - 1] +
                                              p[i][jEnd][iEnd - 1][jEnd] + p[iEnd][jEnd][iEnd][jEnd];
                    }
                    if (p[i][j][iEnd][jEnd] <= k && p[i][j][iEnd][jEnd] > max) {
                        max = p[i][j][iEnd][jEnd];
                    }
                }
            }
        }
    }
    return max;
}

int maxSumSubmatrix2(vector<vector<int>> &matrix, int k) {
    int length = matrix.size();
    int weight = matrix[0].size();
    int max = INT32_MIN;
    int ****p = new int ***[length + 1];

    for (int i = 0; i < length + 1; ++i) {
        p[i] = new int **[weight + 1];
        for (int j = 0; j < weight + 1; ++j) {
            p[i][j] = new int *[length + 1];
            for (int l = 0; l < length + 1; ++l) {
                p[i][j][l] = new int[weight + 1]{0};
            }
        }
    }

    for (int i = 1; i <= length; ++i) {
        for (int j = 1; j <= weight; ++j) {
            for (int iEnd = i; iEnd <= length; ++iEnd) {
                for (int jEnd = j; jEnd <= weight; ++jEnd) {
                    p[i][j][iEnd][jEnd] =
                            p[i][j][iEnd - 1][jEnd] + p[i][j][iEnd][jEnd - 1] - p[i][j][iEnd][jEnd] +
                            matrix[iEnd - 1][jEnd - 1];
                    if (p[i][j][iEnd][jEnd] > max && p[i][j][iEnd][jEnd] <= k) {
                        max = p[i][j][iEnd][jEnd];
                    }
                }
            }
        }
    }
    return max;
}

/**
 * 减少内存
 * @param matrix
 * @param k
 * @return
 */
int maxSumSubmatrix3(vector<vector<int>> &matrix, int k) {
    int length = matrix.size();
    int weight = matrix[0].size();
    int max = INT32_MIN;
    for (int i = 1; i <= length; ++i) {
        for (int j = 1; j <= weight; ++j) {
            int **p = new int *[length + 1];
            for (int i = 0; i < length + 1; ++i) {
                p[i] = new int[weight + 1]{0};
            }
            for (int iEnd = i; iEnd <= length; ++iEnd) {
                for (int jEnd = j; jEnd <= weight; ++jEnd) {
                    p[iEnd][jEnd] =
                            p[iEnd - 1][jEnd] + p[iEnd][jEnd - 1] - p[iEnd - 1][jEnd - 1] +
                            matrix[iEnd - 1][jEnd - 1];
                    if (p[iEnd][jEnd] > max && p[iEnd][jEnd] <= k) {
                        max = p[iEnd][jEnd];
                    }
                }
            }
        }
    }
    return max;
}

/**
 * 固定左右边界
 * @param matrix
 * @param k
 * @return
 */
int maxSumSubmatrix4(vector<vector<int>> &matrix, int k) {
    int length = matrix.size();
    int weight = matrix[0].size();
    int max = INT32_MIN;
    for (int left = 0; left < weight; ++left) {
        int *p = new int[length]{0};
        for (int right = left; right < weight; ++right) {
            for (int i = 0; i < length; ++i) {
                p[i] += matrix[i][right];
            }
            //取数组的中和最大的
            for (int i = 0; i < length; ++i) {
                int sum = 0;
                for (int j = i; j < length; ++j) {
                    sum += p[j];
                    if (sum > max && sum <= k) {
                        max = sum;
                    }
                }
            }
        }
    }
    return max;
}


/**
 * N 叉数的前序遍历
 * @param root
 * @return
 */
vector<int> preorderN(Node *root) {
    if (root == nullptr) {
        return {};
    }
    vector<int> result;
    preOrderHelp(root, result);
    return result;
}

void preOrderHelp(Node *root, vector<int> &result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->val);
    for (int i = 0; i < root->children.size(); ++i) {
        preOrderHelp(root->children[i], result);
    }
}

/**
 * 337.打家劫舍III
 * @param nums
 * @return
 */
int rob3(vector<int> &nums) {
    return 0;
}

/**
 * 337.打家劫舍II
 * @param nums
 * @return
 */
int rob2(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int *p = new int[nums.size()];
    for (int i = 0; i < nums.size(); ++i) {
        p[i] = -1;
    }
    int n = robHelp(nums, 1, p);
    for (int i = 0; i < nums.size(); ++i) {
        p[i] = -1;
    }
    nums.pop_back();
    int m = nums[0] + robHelp(nums, 2, p);
    return n > m ? n : m;
}

/**
 * 198.打家劫舍I
 * @param nums
 * @return
 */
int rob(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int *p = new int[nums.size()];
    for (int i = 0; i < nums.size(); ++i) {
        p[i] = -1;
    }
    return robHelp(nums, 0, p);
}

int robHelp(vector<int> &nums, int index, int *p) {
    if (index >= nums.size()) {
        return 0;
    }
    if (p[index] != -1) {
        return p[index];
    }
    int n = nums[index] + robHelp(nums, index + 2, p);
    int m = robHelp(nums, index + 1, p);
    p[index] = n - m > 0 ? n : m;
    return p[index];
}

/**
 * 贪心+dfs
 * @param coins
 * @param amount
 * @return
 */
int coinChange2(vector<int> &coins, int amount) {


    sort(coins.end(), coins.begin());

    return 0;
}


/**
 * 322.零钱兑换
 * @param coins
 * @param amount
 * @return
 */
int coinChange(vector<int> &coins, int amount) {
    int *temp = new int[amount + 1]{0};
    return coinChangeHelp(coins, temp, amount);
}

int coinChangeHelp(vector<int> &coins, int *temp, int amount) {
    if (amount < 0) {
        return -1;
    }
    if (amount == 0) {
        return 0;
    }
    if (temp[amount] == 0) {
        int min = -1;
        for (int i = coins.size() - 1; i >= 0; --i) {
            int tempNum = coinChangeHelp(coins, temp, (amount - coins[i]));
            if (min == -1 || (tempNum != -1 && min > tempNum)) {
                min = tempNum;
            }
        }
        temp[amount] = min == -1 ? -1 : (min + 1);
    }
    return temp[amount];
}

/**
 * 64.最短路径和
 * @param grid
 * @return
 */
int minPathSum(vector<vector<int>> &grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    int length = grid[0].size();
    int *temp = new int[length];
    temp[0] = grid[0][0];
    for (int i = 1; i < length; ++i) {
        if (i == 0) {

        }
        temp[i] = grid[0][i] + temp[i - 1];
    }
    for (int j = 1; j < grid.size(); ++j) {
        temp[0] = temp[0] + grid[j][0];
        for (int i = 1; i < length; ++i) {
            temp[i] = (temp[i - 1] < temp[i] ? temp[i - 1] : temp[i]) + grid[j][i];
        }
    }
    return temp[length - 1];
}

int maxSubArray(vector<int> &nums) {
    int max = nums[0];
    int temp = max;
    for (int i = 1; i < nums.size(); ++i) {
        if (temp >= 0) {
            temp += nums[i];
        }
        if (temp < 0 && temp < nums[i]) {
            temp = nums[i];
        }
        if (max < temp) {
            max = temp;
        }
    }
    return max;
}

string replaceSpace2(string s) {
    int blankNum = 0;
    int length = s.size();
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            blankNum++;
        }
    }
    s.resize(length + 2 * blankNum);

    int index = s.size() - 1;
    for (int j = length - 1; j >= 0; --j) {
        if (index == j) {
            break;
        }
        if (s[j] == ' ') {
            s[index--] = '0';
            s[index--] = '2';
            s[index--] = '%';
            continue;
        }
        s[index--] = s[j];
    }
    return s;
}

/**
 * 最长公共子序列
 * @param text1
 * @param text2
 * @return
 */
int longestCommonSubsequence(string text1, string text2) {
    int text1Length = text1.size() + 1;
    int text2Length = text2.size() + 1;
    int **p = new int *[text1Length];
    for (int i = 0; i < text1Length; ++i) {
        p[i] = new int[text2Length];
        for (int j = 0; j < text2Length; ++j) {
            //初始化
            p[i][j] = 0;
        }
    }
    for (int k = 1; k < text1Length; ++k) {
        for (int i = 1; i < text2Length; ++i) {
            if (text1[k - 1] == text2[i - 1]) {
                p[k][i] = p[k - 1][i - 1] + 1;
            } else {
                p[k][i] = p[k - 1][i] > p[k][i - 1] ? p[k - 1][i] : p[k][i - 1];
            }
        }
    }
    return p[text1Length - 1][text2Length - 1];
}

int robotSim3(vector<int> &commands, vector<vector<int>> &obstacles) {
    int dirct[4][2] = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };
    int x, y, max, dir;
    x = y = max = dir = 0;
    unordered_map<int, unordered_set<int>> obsSet;
    for (int i = 0; i < obstacles.size(); ++i) {
        if (obsSet.count(obstacles[i][0]) == 0) {
            unordered_set<int> item = {obstacles[i][1]};
            obsSet[obstacles[i][0]] = item;
        } else {
            obsSet[obstacles[i][0]].insert(obstacles[i][1]);
        }
    }

    for (int j = 0; j < commands.size(); ++j) {
        int step = commands[j];
        if (step == -1) {
            dir = (dir + 1) % 4;
        } else if (step == -2) {
            dir = (dir + 3) % 4;
        } else {
            for (int i = 0; i < step; ++i) {
                x += dirct[dir][0];
                y += dirct[dir][1];
                if (obsSet.count(x) == 1 && obsSet[x].count(y) == 1) {
                    x -= dirct[dir][0];
                    y -= dirct[dir][1];
                    break;
                }
            }
            int l = x * x + y * y;
            if (l > max) {
                max = l;
            }
        }
    }


    return max;
}

vector<vector<int>> fourSum2(vector<int> &nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3;) {
        for (int j = i + 1; j < nums.size() - 2;) {
            int k = j + 1;
            int l = nums.size() - 1;
            while (k < l) {
                int temp = nums[i] + nums[j] + nums[k] + nums[l];
                if (temp < target) {
                    do {
                        k++;
                    } while (nums[k - 1] == nums[k] && k < l);
                }
                if (temp == target) {
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    do {
                        k++;
                    } while (nums[k - 1] == nums[k] && k < l);
                    do {
                        l--;
                    } while (nums[l + 1] == nums[l] && k < l);
                }
                if (temp > target) {
                    do {
                        l--;
                    } while (nums[l + 1] == nums[l] && k < l);
                }
            }
            do {
                j++;
            } while (nums[j - 1] == nums[j] && j < nums.size() - 2);
        }
        do {
            i++;
        } while (nums[i - 1] == nums[i] && i < nums.size() - 3);
    }
    return result;
}

/**
 * 跳跃游戏II
 * @param nums
 * @return
 */
int jump2(vector<int> &nums) {
    //最大值一直更新
    int max = 0;
    //当走到临时最大值时，加一
    int step = 0;
    //临时最大值
    int tempMax = 0;
    int length = nums.size() - 1;
    for (int i = 0; i < nums.size() && max >= i; ++i) {
        //当包到最后了
        if (max >= length) {
            return step + 1;
        }
        //一直更新max的值
        if (i + nums[i] > max) {
            max = i + nums[i];
        }
        //上一个阶段走完了，设置下一个阶段
        if (tempMax <= i) {
            step++;
            tempMax = max;
        }
    }
    return 0;
}

/**
 * 跳跃游戏，只要能用贪心就用贪心，贪心虽然是动态规划的子集，但是动态规划的速度是没有办法和贪心作比较的
 * 要经常更新max
 * @param nums
 * @return
 */
bool canJump2(vector<int> &nums) {
    int max = 0;
    int length = nums.size() - 1;
    for (int i = 0; i < nums.size() && i <= max; ++i) {
        if (max >= length) {
            return true;
        }
        if (i + nums[i] > max) {
            max = i + nums[i];
        }
    }
    return false;
}

/**
 * 通过看题解和我的思路一样，将之前的一个节点改成一个数组
 * @param beginWord
 * @param endWord
 * @param wordList
 * @return
 */
vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string> &wordList) {
    return {};
}

/**
 * 复习 单词接龙
 * @param beginWord
 * @param endWord
 * @param wordList
 * @return
 */
int ladderLength2(string beginWord, string endWord, vector<string> &wordList) {
    //单词集合
    unordered_set<string> wordSet;
    for (int k = 0; k < wordList.size(); ++k) {
        wordSet.insert(wordList[k]);
    }
    unordered_set<string> visited;
    //存放每一步的单词
    queue<string> que;
    que.push(beginWord);
    visited.insert(beginWord);
    int step = 0;
    while (!que.empty()) {
        step++;
        int length = que.size();
        for (int k = 0; k < length; ++k) {
            string dealStr = que.front();
            que.pop();
            //步数
            for (int i = 0; i < dealStr.size(); ++i) {
                char tempChar = dealStr[i];
                for (int j = 'a'; j <= 'z'; ++j) {
                    //新的单词
                    dealStr[i] = j;
                    //在单词列表中但是没有使用过
                    if (wordSet.count(dealStr) && visited.count(dealStr) == 0) {
                        if (dealStr == endWord) {
                            return step + 1;
                        }
                        //放到队列中
                        que.push(dealStr);
                        //标记已经访问过了
                        visited.insert(dealStr);
                    }
                }
                dealStr[i] = tempChar;
            }
        }
    }
    return 0;
}

/**
 * 多数元素
 * @param nums
 * @return
 */
int majorityElement(vector<int> &nums) {
    int index = 0;
    int num;
    for (int i = 1; i < nums.size(); ++i) {
        if (index == 0) {
            num = nums[i];
        } else if (nums[i] == num) {
            index++;
        } else {
            index--;
        }
    }
    return num;
}

/**
 * 贪心
 * @param nums
 * @return
 */
int jump(vector<int> &nums) {
    int max = 0;
    int step = 0;
    int end = 0;
    int length = nums.size() - 1;
    for (int i = 0; i < length; ++i) {
        if (max < i + nums[i]) {
            max = i + nums[i];
            if (max >= length) {
                return step + 1;
            }
        }
        if (i == end) {
            end = max;
            step++;
        }
    }
    return step;
}

/**
 * 45.跳跃游戏II
 * @param nums
 * @return
 */
int jumpDT(vector<int> &nums) {
    if (nums.size() <= 1) {
        return 0;
    }
    int *minStep = new int[nums.size()];
    for (int i = 0; i < nums.size(); ++i) {
        minStep[i] = -1;
    }
    return jumpHelp(nums, 0, minStep);
}

int jumpHelp(vector<int> &nums, int index, int *minStep) {
    //最后一跳
    if (nums[index] + index >= nums.size() - 1) {
        return 1;
    }
    //这一跳的范围
    int min = -1;
    for (int i = 1; i <= nums[index]; ++i) {
        int temp = minStep[i + index] != -1 ? minStep[i + index] : jumpHelp(nums, index + i, minStep);
        if (temp != 0 && (min == -1 || min > temp)) {
            min = temp;
        }
    }
    minStep[index] = min + 1;
    return min + 1;
}

/**
 * 126 单词接龙II
 * @param beginWord
 * @param endWord
 * @param wordList
 * @return
 */
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> words;
    for (int i = 0; i < wordList.size(); ++i) {
        words.insert(wordList[i]);
    }
    unordered_set<string> visited;
    queue<vector<string>> que;
    visited.insert(beginWord);
    que.push({beginWord});
    bool flag = true;
    while (flag && !que.empty()) {
        int length = que.size();
        vector<string> tempVisited;
        for (int i = 0; i < length; ++i) {
            vector<string> list = que.front();
            que.pop();
            string dealStr = list.back();
            for (int j = 0; j < dealStr.size(); ++j) {
                char tempChar = dealStr[j];
                for (int k = 'a'; k <= 'z'; ++k) {
                    dealStr[j] = k;
                    if (words.count(dealStr) && visited.count(dealStr) == 0) {
                        list.push_back(dealStr);
                        que.push(list);
                        list.pop_back();
                        tempVisited.push_back(dealStr);
                        if (dealStr == endWord) {
                            flag = false;
                        }
                    }
                }
                dealStr[j] = tempChar;
            }
        }
        //这里存放用到的单词
        for (int l = 0; l < tempVisited.size(); ++l) {
            visited.insert(tempVisited[l]);
        }
    }
    vector<vector<string>> result;
    while (!que.empty()) {
        vector<string> item = que.front();
        que.pop();
        if (item.back() == endWord) {
            result.push_back(item);
        }
    }
    return result;
}

/**
 * 153 搜索数组中的最小值
 * @param nums
 * @return
 */
int findMin(vector<int> &nums) {
    if (nums[0] < nums[nums.size() - 1]) {
        return nums[0];
    }
    int start = 0;
    int end = nums.size() - 1;
    int min;
    while (end - start > 1) {
        min = (start + end) / 2;
        if (nums[start] < nums[min]) {
            start = min;
        } else {
            end = min;
        }
    }
    return nums[end];
}

/**
 * 74 搜索二维矩阵
 * @param matrix
 * @param target
 * @return
 */
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return false;
    }
    int start = 0;
    int end = matrix.size() - 1;
    int min;
    while (start <= end) {
        min = (start + end) / 2;
        if (matrix[min][0] == target) {
            return true;
        }
        if (matrix[min][0] < target) {
            if (matrix[min][matrix[min].size() - 1] >= target) {
                break;
            } else {
                start = min + 1;
            }
        } else {
            end = min - 1;
        }
    }
    start = 0;
    end = matrix[min].size() - 1;
    int min2;
    while (start <= end) {
        min2 = (start + end) / 2;
        if (matrix[min][min2] == target) {
            return true;
        }
        if (matrix[min][min2] < target) {
            start = min2 + 1;
        } else {
            end = min2 - 1;
        }
    }
    return false;
}

/**
 * 33 搜索旋转数组
 * @param nums
 * @param target
 * @return
 */
int search(vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start < end) {
        int min = (start + end) / 2;
        if (nums[min] == target) {
            return min;
        }
        if (nums[start] < nums[min] && nums[start] <= target && nums[min] > target) {
            //前半部分有序并且在有序中
            end = min - 1;
            while (start < end) {
                if (nums[min] < target) {
                    start = min + 1;
                } else {
                    end = min - 1;
                }
                min = (start + end) / 2;
                if (nums[min] == target) {
                    return min;
                }
            }
        }
        if (nums[min] < nums[end] && nums[min] < target && nums[end] >= target) {
            //后半部分有序并且在有序中
            start = min + 1;
            while (start < end) {
                if (nums[min] < target) {
                    start = min + 1;
                } else {
                    end = min - 1;
                }
                min = (start + end) / 2;
                if (nums[min] == target) {
                    return min;
                }
            }
        }
        //在无序的部分中
        if (nums[min] > target) {
            start = min + 1;
        } else {
            end = min - 1;
        }
    }
    return -1;
}

/**
 * 官网解法
 * @param nums
 * @param target
 * @return
 */
int searchGW(vector<int> &nums, int target) {
    int n = (int) nums.size();
    //长度为0
    if (!n) {
        return -1;
    }
    //长度为1
    if (n == 1) {
        return nums[0] == target ? 0 : -1;
    }
    int start = 0, end = n - 1;
    while (start <= end) {
        //去中间值
        int mid = (start + end) / 2;
        //判断中间值
        if (nums[mid] == target) return mid;
        //如果
        if (nums[0] <= nums[mid]) {
            //左边有序
            if (nums[0] <= target && target < nums[mid]) {
                //在左边有序的数组中
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            //右边有序
            if (nums[mid] < target && target <= nums[n - 1]) {
                //在右边有序的数组中
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

/**
 * 55.贪心算法 跳跃游戏
 */

bool canJump(vector<int> &nums) {
    int max = 0;
    for (int i = 0; i < nums.size() && i <= max; ++i) {
        if (max >= nums.size() - 1) {
            return true;
        }
        if (max < i + nums[i]) {
            max = i + nums[i];
        }
    }
    return false;
}

/**
 * [55]跳跃游戏 使用动态规划，超时了
 * @param nums
 * @return
 */
bool canJump1(vector<int> &nums) {
    return canJump(nums, 0);
}

bool canJump(vector<int> &nums, int index) {
    int max = nums[index];
    if (index + max >= nums.size() - 1) {
        return true;
    }
    for (int i = 1; i <= max; ++i) {
        if (canJump(nums, index + i)) {
            return true;
        }
    }
    return false;
}

vector<vector<char>> updateBoard1(vector<vector<char>> &board, vector<int> &click) {
    char deal = board[click[0]][click[1]];
    //挖到雷了
    if (deal == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    if (deal == 'E') {
        int num = landmineNum(board, click[0], click[1]);
        if (num == 0) {
            board[click[0]][click[1]] = 'B';
            for (int i = 0; i < direction529.size(); ++i) {
                int tempI = click[0] + direction529[i][0];
                int tempJ = click[1] + direction529[i][1];
                if (tempI >= 0 && tempI < board.size() && tempJ >= 0 && tempJ < board[tempI].size()) {
                    vector<int> temp = {tempI, tempJ};
                    updateBoard1(board, temp);
                }
            }
        } else {
            board[click[0]][click[1]] = ('0' + num);
        }

    }
    return board;
}

/**
 * 扫雷，这个速度更快
 * @param board
 * @param click
 * @return
 */
vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
    if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    if (board[click[0]][click[1]] == 'E') {
        updateBoardDfs(board, click[0], click[1]);
    }
    return board;
}

void updateBoardDfs(vector<vector<char>> &board, int i, int j) {
    int num = landmineNum(board, i, j);
    if (num == 0) {
        board[i][j] = 'B';
        for (int k = 0; k < direction529.size(); ++k) {
            int tempI = i + direction529[k][0];
            int tempJ = j + direction529[k][1];
            if (tempI >= 0 && tempI < board.size() && tempJ >= 0 && tempJ < board[tempI].size() &&
                board[tempI][tempJ] == 'E') {
                updateBoardDfs(board, tempI, tempJ);
            }
        }
    } else {
        board[i][j] = '0' + num;
    }
}

/**
 * 多少雷
 * @param board
 * @param i
 * @param j
 * @return
 */
int landmineNum(vector<vector<char>> &board, int i, int j) {
    int index = 0;
    for (int k = 0; k < direction529.size(); ++k) {
        int tempI = i + direction529[k][0];
        int tempJ = j + direction529[k][1];
        if (tempI >= 0 && tempI < board.size() && tempJ >= 0 && tempJ < board[tempI].size() &&
            board[tempI][tempJ] == 'M') {
            index++;
        }
    }
    return index;
}

/**
 * 单词接龙 采用图的思想
 * @param beginWord
 * @param endWord
 * @param wordList
 * @return
 */
int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    //存放单词
    unordered_set<string> words;
    //存放问过的节点
    unordered_set<string> visited;
    for (int i = 0; i < wordList.size(); ++i) {
        words.insert(wordList[i]);
    }
    int step = 1;
    visited.insert(beginWord);
    queue<string> visiting;
    visiting.push(beginWord);
    //如果队列不为空
    while (!visiting.empty()) {
        int length = visiting.size();
        for (int i = 0; i < length; ++i) {
            string dealStr = visiting.front();
            visiting.pop();
            //每个单词的长度
            for (int j = 0; j < dealStr.size(); ++j) {
                char temp = dealStr[j];
                //每个位置
                for (int k = 'a'; k <= 'z'; ++k) {
                    dealStr[j] = k;
                    //如果在单词列表中找到了，并且没有访问过，则进行处理
                    if (words.count(dealStr) && visited.count(dealStr) == 0) {
                        //等于最后一个
                        if (dealStr == endWord) {
                            return step + 1;
                        }
                        //放到将要遍历的队列中
                        visiting.push(dealStr);
                        //放到已经访问过得队列
                        visited.insert(dealStr);
                    }
                }
                //改回来
                dealStr[j] = temp;
            }
        }
        step++;
    }
    return 0;

}


/**
 * 单词接龙 求最短路径
 * 使用广度优先搜索
 * 采用的是树的思想
 * @param beginWord
 * @param endWord
 * @param wordList
 * @return
 */
int ladderLengthAboutTree(string beginWord, string endWord, vector<string> &wordList) {

    queue<vector<string>> queue;
    queue.push({beginWord});
    while (!queue.empty()) {
        vector<string> item = queue.front();
        if (item.back() == endWord) {
            return item.size();
        }
        queue.pop();
        for (int i = 0; i < wordList.size(); ++i) {
            if (isOK(item, wordList[i])) {
                item.push_back(wordList[i]);
                queue.push(item);
                item.pop_back();
            }
        }

    }
    return 0;
}

/**
 * 判断该单词是否可以用
 * @param temp
 * @param front
 * @param min
 * @return
 */
bool isOK(vector<string> &temp, string &min) {
    for (int i = 0; i < temp.size(); ++i) {
        if (temp[i] == min) {
            return false;
        }
    }
    return isChangeOne(temp.back(), min);
}


/**
      * 127.单词接龙  求最长路劲 但是人家让求最短路劲
 * @param beginWord
 * @param endWord
 * @param wordList
 * @return
 */

int ladderLengthMax(string beginWord, string endWord, vector<string> &wordList) {
    for (int i = 0; i < wordList.size(); ++i) {
        if (beginWord == wordList[i]) {
            wordList[i] = "";
        }
    }
    int max = ladderLengthHelp(beginWord, endWord, wordList);
    return max < 0 ? 0 : max;
}

/**
 *  寻找最大的接龙
 * @param beginWord
 * @param endWord
 * @param wordList
 * @return 0 表示有尾巴，>0 表示尾巴的长度，-1 表示没有尾巴
 */
int ladderLengthHelp(string beginWord, string endWord, vector<string> &wordList) {
    if (beginWord == endWord) {
        //有尾巴
        return 0;
    }
    int max = -1;
    for (int i = 0; i < wordList.size(); ++i) {
        if (isChangeOne(beginWord, wordList[i])) {
            string tempstr = wordList[i];
            //标记使用
            wordList[i] = "";
            int temp = ladderLengthHelp(tempstr, endWord, wordList);
            //复原
            wordList[i] = tempstr;
            if (temp > max) {
                max = temp + 1;
            }
        }
    }
    return max;
}


/**
 * 单词长度相同并且差一个字符
 */
bool isChangeOne(string &one, string &two) {
    //代表用过
    if (one == two || one == "" || two == "") {
        return false;
    }
    int index = 0;
    for (int i = 0; i < one.length(); ++i) {
        if (one[i] != two[i]) {
            index++;
            if (index > 1) {
                return false;
            }
        }
    }
    return true;
}

/**
 * 367
 *  牛顿迭代法
 * @param num
 * @return
 */
bool isPerfectSquare(int num) {
    if (num < 2) {
        return true;
    }
    int temp = num / 2;
    while (temp * temp > num) {
        temp = (temp + num / temp) / 2;
    }
    return temp * temp == num;
}

/**
 * 岛屿数量
 * @param grid
 * @return
 */
int numIslands(vector<vector<char>> &grid) {
    int index = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '1') {
                index++;
                numIslandsHelp(grid, i, j);
            }
        }
    }
    return index;
}

void numIslandsHelp(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    numIslandsHelp(grid, i + 1, j);
    numIslandsHelp(grid, i - 1, j);
    numIslandsHelp(grid, i, j + 1);
    numIslandsHelp(grid, i, j - 1);

}

/**
 * 模拟机器人行走
 * @param commands
 * @param obstacles
 * @return
 */
int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    int direx[] = {0, 1, 0, -1};
    int direy[] = {1, 0, -1, 0};
    int curx = 0, cury = 0;
    int curdire = 0;
    int comLen = commands.size();
    int ans = 0;
    set<pair<int, int>> obstacleSet;
    for (int i = 0; i < obstacles.size(); i++)
        obstacleSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));

    for (int i = 0; i < comLen; i++) {
        if (commands[i] == -1) {  // -1：向右转 90 度
            curdire = (curdire + 1) % 4;
        } else if (commands[i] == -2) {  // -2：向左转 90 度
            curdire = (curdire + 3) % 4;
        } else {  //  1 <= x <= 9：向前移动 x 个单位长度
            for (int j = 0; j < commands[i]; j++) {
                //试图走出一步，并判断是否遇到了障碍物，
                int nx = curx + direx[curdire];
                int ny = cury + direy[curdire];
                //当前坐标不是障碍点，计算并与存储的最大欧式距离的平方做比较
                if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                    curx = nx;
                    cury = ny;
                    ans = max(ans, curx * curx + cury * cury);
                } else {
                    //是障碍点，被挡住了，停留，只能等待下一个指令，那可以跳出当前指令了
                    break;
                }
            }
        }
    }
    return ans;
}


/**
 * 455 发饼干
 * @param g 孩子的胃口
 * @param s 饼干的大小
 * @return
 */
int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    //第几个孩子
    int index = 0;
    for (int i = 0; i < s.size() && index < g.size(); ++i) {
        if (s[i] >= g[index]) {
            index++;
        }
    }
    return index;
}

/**
 * 柠檬水
 * 列出所有的情况，比较难
 * 执行耗时:24 ms,击败了98.90% 的C++用户
 * 内存消耗:16.1 MB,击败了15.69% 的C++用户
 * @param bills
 * @return
 */
bool lemonadeChange(vector<int> &bills) {
    int bill[2] = {0, 0};
    for (int i = 0; i < bills.size(); ++i) {
        switch (bills[i]) {
            case 5:
                bill[0]++;
                break;
            case 10:
                if (bill[0] > 0) {
                    bill[1]++;
                    bill[0]--;
                } else {
                    return false;
                }
                break;
            case 20:
                if (bill[0] > 0 && bill[1] > 0) {
                    bill[2]++;
                    bill[1]--;
                    bill[0]--;
                } else if (bill[0] > 2) {
                    bill[0] = bill[0] - 3;
                } else {
                    return false;
                }
                break;
        }
    }
    return true;
}

/**
 * 48.旋转图像
 * @param matrix
 *  . . . . . . .
 *  . . . . . . .
 *  . . . . . . .
 *  . . . . . . .
 *  . . . . . . .
 *  . . . . . . .
 *  . . . . . . .
 *  1,2 -> 7,2
 *  7,2 -> 6,7
 *  6,7 -> 6,1
 *  6,1 -> 1,2
 *  a,b ->
 */
void rotate(vector<vector<int>> &matrix) {
    int temp;

    for (int i = 0; i < matrix.size() / 2; ++i) {


    }
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *end = head;
    //先移动n个节点
    while (n > 0 && end != nullptr) {
        n--;
        end = end->next;
    }
    //如果同时为0和nullptr 说明删除第一个节点
    if (n == 0 && end == nullptr) {
        return head->next;
    }
    //说明删除其他节点
    if (n == 0) {
        ListNode *index = head;
        while (end->next != nullptr) {
            end = end->next;
            index = index->next;
        }
        index->next = index->next->next;
    }
    return head;
}

/**
 * 122 买卖股票的最佳时机II
 * @param prices
 * @return
 */
int maxProfit(vector<int> &prices) {

    int sum = 0;
    int min = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        if (min < prices[i]) {
            sum += (prices[i] - min);
        }
        min = prices[i];
    }
    return sum;
}

/**
 * 17.09 第k个数
 * @param k
 * @return
 */
int getKthMagicNumber(int k) {
    vector<int> result = {1};
    int index3 = 0;
    int index5 = 0;
    int index7 = 0;
    while (result.size() < k) {
        int temp3 = result[index3] * 3;
        int temp5 = result[index5] * 5;
        int temp7 = result[index7] * 7;
        int min = temp3;
        if (min > temp5) {
            min = temp5;
        }
        if (min > temp7) {
            min = temp7;
        }
        result.push_back(min);
        if (temp3 == min) {
            index3++;
        }
        if (temp5 == min) {
            index5++;
        }
        if (temp7 == min) {
            index7++;
        }
    }
    return result.back();
}

/**
 * 51. N 皇后问题
 * @param n
 * @return
 */
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<int> temp;
    int *lie = new int[n * 2];
    int *na = new int[n * 2];
    int *pie = new int[n * 2];
    for (int l = 0; l < n * 2; ++l) {
        lie[l] = 0;
        na[l] = 0;
        pie[l] = 0;
    }
    NQueensHelp(result, temp, lie, na, pie,
                n, 0);
    return result;
}

/**
 *
 * @param result
 * @param temp
 * @param n
 * @param k
 */
void
NQueensHelp(vector<vector<string>> &result, vector<int> &temp, int *lie, int *na, int *pie, int n,
            int k) {
    if (n == k) {
        vector<string> item;
        for (int i = 0; i < temp.size(); ++i) {
            string str;
            for (int k = 0; k < n; ++k) {
                if (k == temp[i]) {
                    str += 'Q';
                } else {
                    str += '.';
                }
            }
            item.push_back(str);
        }
        result.push_back(item);
    }
    for (int i = 0; i < n; ++i) {
        if (isTrue(lie, na, pie, n, k, i)) {
            temp.push_back(i);
            lie[i] = 1;
            na[n + k - i] = 1;
            pie[k + i] = 1;
            NQueensHelp(result, temp, lie, na, pie, n, k + 1);
            temp.pop_back();
            lie[i] = 0;
            na[n + k - i] = 0;
            pie[k + i] = 0;
        }
    }
}

bool isTrue(int *lie, int *na, int *pie, int n, int k, int i) {
    if (lie[i]
        || na[n + k - i]
        || pie[k + i]) {
        return false;
    }
    return true;
}


vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    permuteUniqueHelp(result, nums, 0);
    return result;
}

/**
 *
 * 剪掉用过的数
 * @param result
 * @param nums
 * @param k
 */
void permuteUniqueHelp(vector<vector<int>> &result, vector<int> &nums, int k) {
    if (k == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    set<int> used;
    for (int i = k; i < nums.size(); ++i) {
        int temp = nums[i];
        if (used.find(temp) == used.end()) {
            used.insert(temp);
            nums[i] = nums[k];
            nums[k] = temp;
            permuteUniqueHelp(result, nums, k + 1);
            temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;
        }
    }
}

/**
 * 46.全排列
 * @param nums
 * @return
 */
vector<vector<int>> permute2(vector<int> &nums) {
    vector<vector<int>> result;
    permute2Help(result, nums, 0);
    return result;
}

/**
 * 第几个数和后面的数进行交换
 * @param result
 * @param nums
 * @param k
 */
void permute2Help(vector<vector<int>> &result, vector<int> &nums, int k) {
    if (k == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    for (int i = k; i < nums.size(); ++i) {
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
        permute2Help(result, nums, k + 1);
        temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
}

/**
 * 看成选不选的问题
 * 第一步选不选1，第二步选不选2 依次下去
 * @param n
 * @param k
 * @return
 */
vector<vector<int>> combine2(int n, int k) {
    vector<vector<int>> result;
    vector<int> temp;
    combine2Help(result, temp, n, k, 1);
    return result;
}

/**
 *
 * @param result 结果
 * @param temp  临时的
 * @param n 有多少个数
 * @param k 要选多少个数
 * @param i 改选那个数
 */
void combine2Help(vector<vector<int>> &result, vector<int> &temp, int n, int k, int i) {
    if (temp.size() + (n - i + 1) < k) {
        return;
    }
    //选够了
    if (temp.size() == k) {
        result.push_back(temp);
        return;
    }
    combine2Help(result, temp, n, k, i + 1);
    temp.push_back(i);
    combine2Help(result, temp, n, k, i + 1);
    temp.pop_back();
}


/**
 * 77 组合
 * 看成选了什么的问题
 * 第一步选1 ，第二部就要从2开始选一个，依次选下来
 * @param n
 * @param k
 * @return
 */
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> temp = {};
    combineHelp(result, temp, n, k, 1, 0);
    return result;
}

/**
 *
 * @param result 结果
 * @param temp 中间值
 * @param n 1..n
 * @param k 有几个数
 * @param i 该存放第几个数
 * @param j 存放了最大的数
 */
void combineHelp(vector<vector<int>> &result, vector<int> &temp, int n, int k, int i, int j) {
    if (i > k) {
        result.push_back(temp);
        return;
    }
    for (int x = j + 1; x <= n; ++x) {
        temp.push_back(x);
        combineHelp(result, temp, n, k, i + 1, x);
        temp.pop_back();
    }
}

/**
 * 迭代的方式
 * 其实和递归一样只不过本地管理了一个栈
 * @param preorder
 * @param inorder
 * @return
 */
TreeNode *buildTree3(vector<int> &preorder, vector<int> &inorder) {
    //todo 迭代方式
    return nullptr;
}

/**
 * 使用辅助函数进行计算
 * @param preorder
 * @param inorder
 * @return
 */
TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder) {
    return buildTreeHelp(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode *
buildTreeHelp(vector<int> &preorder, vector<int> &inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
    TreeNode *root;
    if (preBegin > preEnd) {
        return nullptr;
    } else {
        //在中序遍历中的坐标
        int rootIndex;
        for (rootIndex = inBegin; rootIndex <= preEnd; rootIndex++) {
            if (inorder[rootIndex] == preorder[preBegin]) {
                break;
            }
        }
        root = new TreeNode(preorder[preBegin],
                            buildTreeHelp(preorder, inorder, preBegin + 1, preBegin + (rootIndex - inBegin),
                                          inBegin,
                                          rootIndex - 1),
                            buildTreeHelp(preorder, inorder, preBegin + (rootIndex - inBegin + 1), preEnd,
                                          rootIndex + 1,
                                          inEnd));
    }
    return root;
}

void show(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << '\t';
    }
    cout << endl;
}


/**
 * 105.根据一棵树的前序遍历与中序遍历构造二叉树
 * @param preorder
 * @param inorder
 * @return
 */
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) {
        return nullptr;
    }
    int rootnum = preorder[0];
    //中序遍历根节点的位置
    int inIndex = 0;
    for (inIndex = 0; inIndex < inorder.size(); ++inIndex) {
        if (inorder[inIndex] == rootnum) {
            break;
        }
    }
    //根节点
    TreeNode *root;
    if (inIndex == 0 && inIndex == inorder.size() - 1) {
        //没有左子树
        root = new TreeNode(preorder[0], nullptr, nullptr);
    } else if (inIndex == 0) {
        // 没有左子树
        vector<int> childPreOrder(preorder.begin() + 1, preorder.end());
        vector<int> childInorder(inorder.begin() + 1, inorder.end());
        root = new TreeNode(preorder[0], nullptr, buildTree(childPreOrder, childInorder));
    } else if (inIndex == inorder.size() - 1) {
        //没有右子树
        vector<int> childPreOrder(preorder.begin() + 1, preorder.end());
        vector<int> childInOrder(inorder.begin(), inorder.end() - 1);
        root = new TreeNode(preorder[0], buildTree(childPreOrder, childInOrder), nullptr);
    } else {
        //左子树中序遍历
        vector<int> leftInOrder(inorder.begin(), inorder.begin() + inIndex);
        //左子树前序遍历
        vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + (leftInOrder.size() + 1));
        //右子树前序遍历
        vector<int> rightPreOrder(preorder.begin() + (leftInOrder.size() + 1), preorder.end());
        //右子树中序遍历
        vector<int> rightInOrder(inorder.begin() + (inIndex + 1), inorder.end());
        root = new TreeNode(preorder[0], buildTree(leftPreOrder, leftInOrder),
                            buildTree(rightPreOrder, rightInOrder));
    }
    return root;
}

/**
 * 236.公共祖先问题
 * @param root
 * @param p
 * @param q
 * @return
 */
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr && right == nullptr) {
        return nullptr;
    }
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    return root;
}


TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> pParent;
    vector<TreeNode *> qParent;
    parentNode(root, p, pParent);
    parentNode(root, q, qParent);
    int indexp = pParent.size() - 1;
    int indexq = qParent.size() - 1;
    int result = indexp;
    while (indexp >= 0 && indexp >= 0 && pParent[indexp] == qParent[indexq]) {
        result = indexp;
        indexp--;
        indexq--;
    }
    return pParent[result];
}


bool parentNode(TreeNode *root, TreeNode *p, vector<TreeNode *> &parent) {
    if (root == p) {
        parent.push_back(root);
        return true;
    }
    if (root == nullptr) {
        return false;
    }
    bool flag = false;
    if (flag = parentNode(root->left, p, parent)) {
        parent.push_back(root);
    }
    if (!flag && (flag = parentNode(root->right, p, parent))) {
        parent.push_back(root);
    }
    return flag;
}

vector<int> reversePrint(ListNode *head) {
    vector<int> result;
    reversePrintHelp(head, result);
    return result;
}


void reversePrintHelp(ListNode *head, vector<int> &result) {
    if (head != nullptr) {
        reversePrintHelp(head->next, result);
        result.push_back(head->val);
    }
}

/**
 * 最长同值路径
 * @param root
 * @return
 */
int longestUnivaluePath(TreeNode *root) {

    if (root == nullptr) {
        return 0;
    }
    return 1;
}


/**
 * 替换空格
 * @param s
 * @return
 */
string replaceSpace(string s) {
    string result;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            result += s[i];
        } else {
            result += "%20";
        }
    }
    return result;
}


/**
 * 生括号生成
 * @param n
 * @return
 */
vector<string> generateParenthesis(int n) {
    set<string> b;
    generateParenthsisHelp(n, "", b);
    vector<string> a(b.begin(), b.end());
    return a;
}

/**
 * 辅助函数
 *  相对来说比较麻烦不过我觉得这样会快一些，其实也快不了了哪里
 * @param n
 * @param a
 * @return
 */
void generateParenthsisHelp(int n, vector<string> &a, vector<string> &b) {
    if (n > 0) {
        int lengthA = a.size();
        int lengthB = b.size();
        for (int i = 0; i < lengthA; ++i) {
            string temp = a[i];
            a[i] = '(' + temp + ')';
            a.push_back("()" + temp);
            if (temp[0] == '(' && temp[1] == ')') {
                b.push_back(temp + "()");
            } else {
                a.push_back(temp + "()");
            }
        }
        for (int j = 0; j < lengthB; ++j) {
            string temp = b[j];
            b[j] = '(' + temp + ')';
            b.push_back("()" + temp);
            b.push_back(temp + "()");
        }
        generateParenthsisHelp(n - 1, a, b);
    }
}

/**
 * 傻递归
 * @param n
 * @param temp
 * @param a
 */
void generateParenthsisHelp(int n, string temp, set<string> &a) {
    if (n == 0) {
        a.insert(temp);
        return;
    }
    generateParenthsisHelp(n - 1, temp + "()", a);
    generateParenthsisHelp(n - 1, "()" + temp, a);
    generateParenthsisHelp(n - 1, '(' + temp + ')', a);
}

/**
 * 有缓存的递归
 */
//vector<string> generateParenthsisHelp3(int n, set<string> a) {
//    if (n == 0) {
//        vector<string> b(a.begin(), a.end());
//        return b;
//    }
//    int t = a.size();
//    for (int i = 0; i < t; ++i) {
//
//    }
//}

/**
 * Morris 中序遍历
 * @param root
 * @return
 */
//vector<int> inorderTraversalMorris(TreeNode *root) {
///*    vector<int> res;
//    TreeNode *predecessor = nullptr;
//
//    while (root != nullptr) {
//        if (root->left != nullptr) {
//            // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
//            predecessor = root->left;
//            //找最右节点
//            while (predecessor->right != nullptr && predecessor->right != root) {
//                predecessor = predecessor->right;
//            }
//            // 让 predecessor 的右指针指向 root，继续遍历左子树
//            if (predecessor->right == nullptr) {
//                predecessor->right = root;
//                root = root->left;
//            } else {
//                // 说明左子树已经访问完了，我们需要断开链接
//                res.push_back(root->val);
//                predecessor->right = nullptr;
//                root = root->right;
//            }
//        } else {
//            // 如果没有左孩子，则直接访问右孩子
//            res.push_back(root->val);
//            root = root->right;
//        }
//    }
//    return res;*/
//    vector<int> result;
//    TreeNode *temp;
//    while (root != nullptr) {
//        if (root->left != nullptr) {
//            temp = root->left;
//            while (temp->right != nullptr && temp->right != root) {
//                temp = temp->right;
//            }
//            if (temp->right == nullptr) {
//                temp->right = root;
//                root = root->left;
//            } else {
//                result.push_back(root->val);
//                temp->right = nullptr;
//                root = root->right;
//            }
//        } else {
//            result.push_back(root->val);
//            //遍历右子树
//            root = root->right;
//        }
//    }
//}


/**
 *
 * @param root
 * @return
 */
int maxDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root - right);
    return 1 + left > right ? left : right;
}

/**
 * 前k个高频词汇
 * @param nums
 * @param k
 * @return
 */
vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> countMap;
    for (int i = 0; i < nums.size(); ++i) {
        if (countMap.count(nums[i]) == 0) {
            countMap[nums[i]] = 1;
        } else {
            countMap[nums[i]]++;
        }
    }
    priority_queue<pair<int, int>> q;
    map<int, int>::iterator iterator = countMap.begin();
    while (iterator != countMap.end()) {
        q.push(pair<int, int>(iterator->second, iterator->first));
        iterator++;
    }
    vector<int> result;
    for (int j = 0; j < k; ++j) {
        result.push_back(q.top().second);
        q.pop();
    }
    return result;
}

/**
 * 丑数 暴力解法
 * @param n
 * @return
 */
int nthUglyNumber(int n) {
    int count = 0;
    int i = 0;
    while (count < n) {
        i++;
        if (isUglyNumber(i)) {
            count++;
        }
    }
    return i;
}

/**
 * 使用 动态规划
 *  有三个数
 *  a=1,b=1,c=1
 *
 * @param n
 * @return
 */
int nthUglyNumber2(int n) {
    vector<int> temp;
    temp.push_back(1);
    int var[] = {0, 0, 0};
    for (int i = 1; i < n; ++i) {
        int num[3];
        num[0] = temp[var[0]] * 2;
        num[1] = temp[var[1]] * 3;
        num[2] = temp[var[2]] * 5;
        int min =
                num[0] < num[1] ? (num[0] < num[2] ? num[0] : num[2]) : (num[1] < num[2] ? num[1] : num[2]);
        temp.push_back(min);
        for (int j = 0; j < 3; ++j) {
            if (num[j] == min) {
                var[j]++;
            }
        }
//        for (int k = 0; k < 3; ++k) {
//            cout << var[k] << '\t';
//        }
//        cout << endl;
    }
    return temp.back();
}

bool isUglyNumber(int n) {
    while (n % 2 == 0) {
        n = n / 2;
    }
    while (n % 3 == 0) {
        n = n / 3;
    }
    while (n % 5 == 0) {
        n = n / 5;
    }
    if (n == 1) {
        return true;
    }
    return false;
}


/**
 * 递归层次遍历
 * @param root
 * @return
 */
vector<vector<int>> levelOrder2(Node *root) {
    return {{}};
}

/**
 *
 * @param roots
 * @param result
 * @return
 */
vector<vector<int>> levelOrderHelp(vector<Node *> children, vector<vector<int>> &result) {
//    if (children.size() == 0) {
//        return result;
//    }
//    vector<int> items;
//    vector<Node*> childrenNext;
//    for(auto child:children){
//        if(child==NULL){
//            continue;
//        }
//        items.push_back(child->val);
//        childrenNext.push_back(child)
//
//    }
    return {{}};
}

/**
 * n叉数的层次遍历
 * @param root
 * @return
 */
vector<vector<int>> levelOrder(Node *root) {
    if (root == NULL) {
        return {{}};
    }
    queue<Node *> current;
    current.push(root);
    vector<vector<int>> result;
    while (current.size() > 0) {
        queue<Node *> next;
        vector<int> items;
        while (!current.empty()) {
            //处理第一个
            items.push_back(current.front()->val);
            vector<Node *> children = current.front()->children;
            for (int i = 0; i < children.size(); ++i) {
                if (children[i] != NULL) {
                    next.push(children[i]);
                }
            }
            //删除第一个
            current.pop();
        }
        result.push_back(items);
        current = next;
    }
    return result;
}


/**
 * 二叉树的前序遍历
 * @param root
 * @return
 */
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    return preorderTraversalHelp(root, result);
}

vector<int> preorderTraversalHelp(TreeNode *root, vector<int> &result) {
    if (root == NULL) {
        return result;
    }
    result.push_back(root->val);
    preorderTraversalHelp(root->left, result);
    preorderTraversalHelp(root->right, result);
    return result;
}

/**
 * 二叉树的中序遍历
 */
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    return inorderTraversalHelp(root, result);
}

vector<int> inorderTraversalHelp(TreeNode *root, vector<int> &result) {
    if (root == NULL) {
        return result;
    }
    inorderTraversalHelp(root->left, result);
    result.push_back(root->val);
    inorderTraversalHelp(root->right, result);
    return result;
}

/**
 * 字母异位词分组
 * @param strs
 * @return
 */
vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> result;
    for (int i = 0; i < strs.size(); ++i) {
        string deal_string = strs[i];
        sort(deal_string.begin(), deal_string.end());
        result[deal_string].push_back(strs[i]);
    }
    vector<vector<string >> res;
    map<string, vector<string>>::iterator item;
    for (item = result.begin(); item != result.end(); item++) {
        res.push_back(item->second);
    }
    return res;
}

/**
 * n叉数的前序遍历
 * @param root
 * @return
 */
vector<int> preorder(Node *root) {
    vector<int> result;
    return preorderhelp(root, result);
}

vector<int> preorderhelp(Node *root, vector<int> &result) {
    result.push_back(root->val);
    vector<Node *> children = root->children;
    for (int i = 0; i < children.size(); ++i) {
        preorderhelp(children[i], result);
    }
    return result;
}

/**
 * 有效的字母移位词
 * @param s
 * @param t
 * @return
 */
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    int count[26];
    for (int k = 0; k < 26; ++k) {
        count[k] = 0;
    }

    for (int i = 0; i < s.size(); ++i) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int j = 0; j < 26; ++j) {
        if (count[j] != 0) {
            return false;
        }
    }
    return true;
}

/**
 * 数学法
 * @param num
 * @return
 */
int addDigits2(int num) {
    return num == 0 ? 0 : num % 9;
}

/**
 * 各位相加
 * @param num
 * @return
 */
int addDigits(int num) {
    while (num >= 10) {
        int temp = 0;
        while (num > 0) {
            temp += num % 10;
            num = num / 10;
        }
        num = temp;
    }
    return num;
}

/**
 * Fizz Buzz
 * @param n
 * @return
 */
vector<string> fizzBuzz(int n) {
    vector<string> result;
    for (int i = 1; i <= n; ++i) {
        string item;
        bool flag = false;
        if (i % 3 == 0) {
            item += "Fizz";
            flag = true;
        }
        if (i % 5 == 0) {
            item += "Buzz";
            flag = true;
        }
        if (flag) {
            result.push_back(item);
        } else {
            result.push_back(to_string(i));
        }
    }
    return result;
}

/**
 * 删除最外层的括号
 * n=0&&(
 * n=0&&)
 * @param S
 * @return
 */
string removeOuterParentheses(string S) {
    int n = 0;
    string result = "";
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == '(') {
            n++;
            if (n == 1) {
                continue;
            }
        }
        if (S[i] == ')') {
            n--;
            if (n == 0) {
                continue;
            }
        }
        result += S[i];
    }
    return result;
}


/**
 * 滑动窗口最大值
 * @param nums
 * @param k
 * @return
 */
vector<int> maxSlidingWindow(vector<int> &nums, int
k) {
    deque<int> queue;
    vector<int> result;
    for (
            int i = 0;
            i < nums.

                    size();

            ++i) {
        if (!queue.

                empty() &&

            i - queue.

                    front()

            >= k) {
//元素过期
            queue.

                    pop_front();

        }

//尾元素小于待插入元素
        while (!queue.

                empty() &&

               nums[queue.

                       back()

               ] < nums[i]) {
            queue.

                    pop_back();

        }
        queue.
                push_back(i);

        if (i < k - 1) {
            continue;
        }
        result.
                push_back(nums[queue[0]]);
    }
    return
            result;
}

/**
 * 两个数组的交集
 * @param nums1
 * @param nums2
 * @return
 */
vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> result;
    for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
        if (nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }
    return result;
}

/**
 * 接雨水
 * @param height
 * @return
 */
int trap(vector<int> &height) {
    int sum = 0;
    int left = 0;
    int left_max = 0;
    int right = height.size() - 1;
    int right_max = right;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > height[left_max]) {
                left_max = left;
            } else {
                sum += (height[left_max] - height[left]);
            }
            left++;
        } else {
            if (height[right] > height[right_max]) {
                right_max = left;
            } else {
                sum += (height[right_max] - height[right]);
            }
            right--;
        }
    }
    return sum;
}


/**
 * 合并两个有顺序数组
 * @param nums1
 * @param m
 * @param nums2
 * @param n
 */
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int resultIndex = m + n - 1;
    int index1 = m - 1;
    int index2 = n - 1;
    while (index1 >= 0 && index2 >= 0) {
        if (nums1[index1] > nums2[index2]) {
            nums1[resultIndex--] = nums1[index1--];
        } else {
            nums1[resultIndex--] = nums2[index2--];
        }
    }
    while (index2 >= 0) {
        nums1[resultIndex--] = nums2[index2--];
    }
}

/**
 * 283.移动零
 * @param nums
 */
void moveZeroes(vector<int> &nums) {
    int size = nums.size();
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] != 0) {
            nums[index++] = nums[i];
        }
    }
    for (; index < size; ++index) {
        nums[index] = 0;
    }
}

/**
 * 299.猜谜语
 * 使用hashmap 加vector方式
 * @param secret
 * @param guess
 * @return
 */
string getHint(string secret, string guess) {
    int table[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int x, y = 0;
    for (int i = 0; i < secret.size(); ++i) {
        if (secret[i] == guess[i]) {
            x++;
            guess[i] = 'a';
            continue;
        }

        table[secret[i] - '0']++;
    }
    for (int j = 0; j < guess.size(); ++j) {
        if (guess[j] == 'a') {
            continue;
        }
        if (table[guess[j] - '0'] == 0) {
            continue;
        }
        table[guess[j] - '0']--;
        y++;
    }
    return to_string(x) + "A" + to_string(y) + "B";
}

/**
 * 旋转数组
 * @param nums
 * @param k
 */
void rotate(vector<int> &nums, int
k) {
//存放临时数据
    int temp = nums[0];
//数组长度
    int size = nums.size();
//交换了多少次
    int count = 0;
//每轮第一次的坐标是多少
    int firstIndex = 0;
//交换坐标
    int index = 0;
//交换后的下一个位置
    int next = 0;
    while (count < size) {
        next = (index + k) % size;
        if (firstIndex == next) {
            nums[firstIndex] =
                    temp;
            count++;
            firstIndex = (firstIndex + 1) % size;
            index = firstIndex;
            temp = nums[index];
            continue;
        }
        int n = nums[next];
        nums[next] =
                temp;
        temp = n;
        index = next;
        count++;
    }
}

/**
 * 删除排序数组中的重复项
 * @param nums
 * @return
 */
int removeDuplicates2(vector<int> &nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    int id = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[id] != nums[i]) {
            nums[++id] = nums[i];
        }
    }
    return id + 1;
}

/**
 * 两个队列的合并 递归
 * @param l1
 * @param l2
 * @return
 */
ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
    if (l1 == NULL || l2 == NULL) {
        if (l1 == NULL) {
            return l2;
        }
        return l1;
    }
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists2(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists2(l1, l2->next);
        return l2;
    }
}

ListNode *mergeTwoLists3(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode();
    ListNode *tail = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        } else {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
    }
    tail->next = l1 != NULL ? l1 : l2;
    return head->next;
}

/**
 * 非递归形式
 * @param head
 * @return
 */

/**
 * 递归形式
 * @param head
 * @return
 */
ListNode *swapPairs3(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *p = head->next;
    head->next = swapPairs3(p->next);
    p->next = head;
    return p;
}

/**
 *
 * @param head
 * @return
 */
ListNode *swapPairs2(ListNode *head) {
    ListNode *p = head;
    ListNode *top = NULL;
    ListNode *tail = NULL;
    head = NULL;
    //头插法将两个节点倒叙
    while (p != NULL) {
        top = p;
        p = p->next;
        if (p != NULL) {
            tail = p;
            p = p->next;
            tail->next = head;
            head = top;
        } else {
            top->next = head;
            head = top;
        }
    }
    //头插法将所有的倒叙
    p = head;
    head = NULL;
    while (p != NULL) {
        top = p;
        p = p->next;
        top->next = head;
        head = top;
    }
    return head;
}


/**
 * 两个数之和
 * 1. 暴力方法
 * 2. 排序加双指针
 * 3. hash表
 */

/**
 * 两个数之和
 * @param nums
 * @param target
 * @return
 */
vector<int> twoSum2(vector<int> &nums, int target) {
//排序
    sort(nums.begin(), nums.end());
    vector<int> result;
//双指针
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

vector<int> twoSum2HashTable(vector<int> &nums, int target) {
//创建一个hash表
    unordered_map<int, int> table;

    for (int i = 0; i < nums.size(); ++i) {
        //查询是否有对应的值
        auto item = table.find(target - nums[i]);
        //如果有就返回
        if (item != table.end()) {
            return {item->second, i};
        }
        //如果没有就添加到hash表中
        table[nums[i]] = i;
    }
    return {};
}

/**
 * 加一
 * @param digits
 * @return
 */
vector<int> plusOne(vector<int> &digits) {
    int n = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
        n += digits[i];
        digits[i] = n % 10;
        n /= 10;
        if (n == 0) {
            break;
        }
    }
    if (n == 1) {
        digits.insert(digits.begin(), n);
    }
    return digits;
}

/**
 *
 * @param n
 * @return
 */
int climbStairs2(int n) {
    if (n <= 2) {
        return n;
    }
    long k1 = 1;
    long k2 = 2;
    for (int i = 3; i <= n; ++i) {
        long temp = k2;
        k2 += k1;
        k1 = temp;
    }
    return k2;
}

/**
 * 比较含有退格的字符串
 * 双指针法
 * 执行耗时:0 ms,击败了100.00% 的C++用户
 * 内存消耗:6.3 MB,击败了51.05% 的C++用户
 * @param S
 * @param T
 * @return
 */
bool backspaceCompare(string S, string T) {
    int s_black = 0;
    int t_black = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] != '#') {
            S[s_black++] = S[i];
        } else if (s_black > 0) {
            s_black--;
        }
    }
    for (int j = 0; j < T.length(); ++j) {
        if (T[j] != '#') {
            T[t_black++] = T[j];
        } else if (t_black > 0) {
            t_black--;
        }
    }
    if (s_black != t_black) {
        return false;
    }
    for (int k = 0; k < s_black; ++k) {
        if (S[k] != T[k]) {
            return false;
        }
    }
    return true;
}

//bool backspaceCompare2(string s, string t) {
//
//}

/**
 * 32. 最长有效括号 !!!
 *
 * @param s
 * @return
 */
int longestValidParentheses2_2(string s) {
    int max = 0;
    stack<char> st;
    int index = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s.at(i) == '(') {
            st.push('(');
            index++;
        } else if (!st.empty()) {
            index++;
            st.pop();
        } else {
            if (index > max) {
                max = index;
            }
            index = 0;
        }
    }
    index -= st.size();
    if (index > max) {
        max = index;
    }
    return max;
}

/**
 * 24.两两交换链表中的节点
 * 执行耗时:4 ms,击败了66.12% 的C++用户
 * 内存消耗:7.5 MB,击败了5.06% 的C++用户
 * @param head
 * @return
 */
ListNode *swapPairs(ListNode *head) {
    ListNode *h1 = NULL;
    while (head != NULL) {
        ListNode *h = head;
        ListNode *t = NULL;
        head = head->next;
        if (head == NULL) {
            t = h;
        } else {
            t = head;
        }
        if (head != NULL) {
            head = head->next;
        }
        t->next = h1;
        h1 = h;
    }
    head = h1;
    h1 = NULL;
    while (head != NULL) {
        ListNode *h = head;
        head = head->next;
        h->next = h1;
        h1 = h;
    }
    return h1;
}

/**
 * 54.螺旋矩阵
 * 执行耗时:0 ms,击败了100.00% 的C++用户
 * 内存消耗:6.8 MB,击败了20.05% 的C++用户
 * @param matrix
 * @return
 */
vector<int> spiralOrder(vector<vector<int >> &matrix) {
    vector<int> result;
    int top = 0;
    int left = 0;
    int down = matrix.size() - 1;
    if (down < 0) {
        return vector<int>();
    }
    int right = matrix[0].size() - 1;

    while (top <= down && left <= right) {
        //向右
        for (int i = left; i <= right; ++i) {
            result.push_back(matrix[top][i]);
        }
        top++;
        if (top > down) {
            break;
        }
        //向下
        for (int j = top; j <= down; ++j) {
            result.push_back(matrix[j][right]);
        }
        right--;
        if (left > right) {
            break;
        }
        //向左
        for (int k = right; k >= left; --k) {
            result.push_back(matrix[down][k]);
        }
        down--;
        if (top > down) {
            break;
        }
        //向上
        for (int l = down; l >= top; --l) {
            result.push_back(matrix[l][left]);
        }
        left++;
    }

    return result;
}


/**
 * 8.字符串转化成整数
 * 执行耗时:12 ms,击败了14.97% 的C++用户
 * 内存消耗:6.3 MB,击败了25.32% 的C++用户
 * @param s
 * @return
 */
int myAtoi(string s) {
    bool flag = true;
    int positive = 0;
    long long sum = 0;

    for (int index = 0; index < s.length(); index++) {
        char a = s.at(index);
        //清除空白字符
        if (flag && a == ' ') {
            continue;
        }
        flag = false;
        //开始取字符 符号的判断
        if (positive == 0) {
            if (a == '-') {
                positive = -1;
                continue;
            } else {
                positive = 1;
                if (a == '+') {
                    continue;
                }
            }
        }
        //数字的判断
        int temp = a - '0';
        if (temp >= 0 && temp < 10) {
            sum = sum * 10 + temp;
        } else {
            break;
        }
        if (positive > 0 && sum > INT32_MAX) {
            return INT32_MAX;
        }
        if (positive < 0 && sum * positive < INT32_MIN) {
            return INT32_MIN;
        }
    }
    return sum * positive;
}

/**
 * 26.给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度
 *
 * 执行耗时:12 ms,击败了99.10% 的C++用户
 * 内存消耗:13.4 MB,击败了8.47% 的C++用户
 *
 * @param nums
 * @return
 */
int removeDuplicates(vector<int> &nums) {
    int numsLength = nums.size();
    if (numsLength == 0) {
        return numsLength;
    }
    int index = 0;
    for (int i = 1; i < numsLength; ++i) {
        if (nums[i] == nums[index]) {
            continue;
        } else {
            int temp = nums[++index];
            nums[index] = nums[i];
            nums[i] = temp;
        }
    }
    return index + 1;

}

/**
 * 21 合并两个有序链表
 * 执行耗时:12 ms,击败了53.97% 的C++用户
 * 内存消耗:14.6 MB,击败了5.26% 的C++用户
 * @param l1
 * @param l2
 * @return
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode();
    ListNode *p = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            p->next = l2;
            l2 = l2->next;
        } else {
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }
    if (l1 == NULL) {
        p->next = l2;
    } else {
        p->next = l1;
    }
    return head->next;
}

/**
 * 5.最长的回文子串
 * 执行耗时:128 ms,击败了61.30% 的C++用户
 * 内存消耗:6.9 MB,击败了81.10% 的C++用户
 * 想做扩展
 * 香油扩展
 * 同时向两遍扩展
 * @param s
 * @return
 */
string longestPalindrome(string s) {
    int size = s.length();
    int max = 0;
    int start = 0;
    for (int i = 0; i < size; ++i) {
        int left = i;
        int right = i;
        //向左扩展
        while (left >= 0 && s.at(left) == s.at(i)) {
            left--;
        }
        //向右扩展
        while (right < size && s.at(right) == s.at(i)) {
            right++;
        }
        //同时向两侧扩展
        while (left >= 0 && right < size && s.at(left) == s.at(right)) {
            left--;
            right++;
        }
        left++;
        right--;
        if (max < right - left + 1) {
            max = right - left + 1;
            start = left;
        }

    }
    return s.substr(start, max);
}

/**
 * 63.不同路径
 * 4 ms,击败了96.28% 的C++用户
 * 7.7 MB,击败了71.63% 的C++用户
 * @param obstacleGrid
 * @return
 */
int uniquePathsWithObstacles(vector<vector<int >> &obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<int> countBoard(m);
    //初始化
    for (int i = 0; i < m; ++i) {
        countBoard[i] = 0;
    }
    countBoard[0] = (obstacleGrid[0][0] == 0);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[j][i] == 1) {
                countBoard[i] = 0;
            } else if (i > 0) {
                countBoard[i] += countBoard[i - 1];
            }
        }
    }
    return countBoard.back();
}

/**
 * 62.不同路径
 *内存消耗:5.7 MB,击败了98.30% 的C++用户
 * 执行耗时:0 ms,击败了100.00% 的C++用户
 * @param m
 * @param n
 * @return
 */
int uniquePaths(int m, int n) {
    int sum = m + n - 2;
    long up = 1;
    if (m < n) {
        n = m;
    }
    n--;
    for (int i = 0; i < n; ++i) {
        up *= (sum - i);
    }
    long down = 1;
    for (int j = 2; j <= n; ++j) {
        down *= j;
    }
    return up / down;

}

/**
 * 18.四个数求和
 * 执行耗时:112 ms,击败了42.65% 的C++用户
 * 内存消耗:12.6 MB,击败了5.02% 的C++用户
 * @param nums
 * @param target
 * @return
 */
vector<vector<int>> fourSum(vector<int> &nums, int
target) {
    vector<vector<int>> result;
    int length = nums.size();
    if (length < 4) {
        return
                result;
    }
    sort(nums
                 .

                         begin(), nums

                 .

                         end()

    );
    for (int i = 0; i < length - 2; ++i) {
        for (int j = length - 1; j > i + 2; j--) {
            int n = i + 1;
            int m = j - 1;
            while (n < m) {
                int sum = nums[i] + nums[j] + nums[n] + nums[m];
                if (sum == target) {
                    result.push_back({
                                             nums[i], nums[j], nums[n++], nums[m--]});
                    while (nums[n] == nums[n - 1] && n < m) {
                        n++;
                    }
                    while (nums[m] == nums[m + 1] && n < m) {
                        m--;
                    }
                } else if (sum < target) {
                    n++;
                    while (nums[n] == nums[n - 1] && n < m) {
                        n++;
                    }
                } else {
                    m--;
                    while (nums[m] == nums[m + 1] && n < m) {
                        m--;
                    }
                }
            }
            while (nums[j] == nums[j - 1] && j > i + 2) {
                j--;
            }
        }
        while (nums[i] == nums[i + 1] && i < length - 2) {
            i++;
        }
    }
    return result;
}

/**
 * 15. 三个数之和
 * 104 ms,击败了75.35% 的C++用户
 * :19.8 MB,击败了38.72% 的C++用户
 *
 * @param nums
 * @return
 */
vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) {
        return result;
    }
    sort(nums.begin(), nums.end());
    int length = nums.size();
    //第一个数字必须小于0
    int i = 0;
    while (i < length - 2 && nums[i] <= 0) {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                result.push_back({nums[i], nums[j++], nums[k--]});
                //移动到下一个不同的数字
                while (nums[j - 1] == nums[j] && j < k) {
                    j++;
                }
                //移动到下一个不同的数字
                while (nums[k] == nums[k + 1] && j < k) {
                    k--;
                }
            } else if (sum > 0) {
                k--;
                while (nums[k] == nums[k + 1] && j < k) {
                    k--;
                }
            } else {
                j++;
                while (nums[j] == nums[j - 1] && j < k) {
                    j++;
                }
            }
        }
        while (nums[i] == nums[i + 1] && i < nums.size() - 3) {
            i++;
        }
        i++;
    }
    return result;
}


/**
 * 17 电话号码的字母组合
 *内存消耗:6.3 MB,击败了99.50% 的C++用户
 *执行耗时:4 ms,击败了49.67% 的C++用户
 * @param digits
 * @return
 */
vector<string> letterCombinations(string digits) {
    if (digits == "") {
        return vector<string>();
    }
    vector<string> result;
    string resultString(digits);
    letterCombinationsHelp(digits, resultString, 0, result);
    return result;
}

/**
 * @param digits  输入的数字
 * @param resultString 运行时的结果
 * @param n 处理第几个字符
 * @param result 将所有的结果放到该集合中
 */

void letterCombinationsHelp(string &digits, string &resultString, int n, vector<string> &result) {
    if (n == digits.size()) {
        result.push_back(string(resultString));
    }
    string list = digitsToLetter(digits[n]);
    for (int i = 0; i < list.size(); ++i) {
        resultString[n] = list[i];
        letterCombinationsHelp(digits, resultString, n + 1, result);
    }

}

string digitsToLetter(char digits) {
    switch (digits) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
    }
    return "";
}


/**
 * 46 全排列
 * 4 ms,击败了88.86% 的C++用户
 * 7.7 MB,击败了21.73% 的C++用户
 * @param nums
 * @return
 */
vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    permute_help(nums, nums.size(), result);
    return result;
}

void permute_help(vector<int> &nums, int
n,
                  vector<vector<int>> &result
) {
    if (n == 0) {
        vector<int> copy(nums);
        result.
                push_back(copy);
    }
    for (
            int i = 0;
            i < n;
            ++i) {
        int temp = nums[i];
        nums[i] = nums[n - 1];
        nums[n - 1] =
                temp;
        permute_help(nums, n
                           - 1, result);
        nums[n - 1] = nums[i];
        nums[i] =
                temp;
    }
}

/**
 * 37.解数独
 * 内存消耗:6.6 MB,击败了51.30% 的C++用户
 * 执行耗时:12 ms,击败了43.67% 的C++用户
 * @param board
 */
void solveSudoku(vector<vector<char >> &board) {
    solveSudokuHelp(0, board);
}

bool solveSudokuHelp(int n, vector<vector<char>> &board) {
    if (n == 81) {
        return true;
    }
    int x = n % 9;
    int y = n / 9;
    char value = board[y][x];
    //如果有值就不用做
    if (value != '.') {
        return solveSudokuHelp(n + 1, board);
    }

    int temp[3][9] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    for (int i = 0; i < 9; ++i) {
        if (board[y][i] != '.') {
            if (temp[0][board[y][i] - '1']++ != 0) {
                return false;
            }
        }
        char c = board[i][x];
        if (c != '.') {
            if (temp[1][c - '1']++ != 0) {
                return false;
            }
        }
    }
    int indexX = x / 3;
    int indexY = y / 3;
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            if (board[indexY * 3 + j][indexX * 3 + i] != '.') {
                if (temp[2][board[indexY * 3 + j][indexX * 3 + i] - '1']++ != 0) {
                    return false;
                }
            }
        }
    }
    for (int k = 0; k < 9; ++k) {
        if (!(temp[0][k] || temp[1][k] || temp[2][k])) {
            board[y][x] = '1' + k;
            if (solveSudokuHelp(n + 1, board)) {
                return true;
            }
            board[y][x] = '.';
        }
    }
    return false;
}

/**
 * 36.数独是否有效
 * 执行耗时:12 ms,击败了92.20% 的C++用户
 * 内存消耗:6.9 MB,击败了88.52% 的C++用户
 * @param board
 * @return
 */
bool isValidSudoku(vector<vector<char >> &board) {
    //横向验证
    for (int i = 0; i < 9; ++i) {
        int temp[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int j = 0; j < 9; ++j) {
            int index = (int) board[i][j] - '1';
            if (index < 0 || index > 9) {
                continue;
            }
            if (temp[index]++ != 0) {
                return false;
            }
        }
    }
    //竖向验证
    for (int i = 0; i < 9; ++i) {
        int temp[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int j = 0; j < 9; ++j) {
            int index = (int) board[j][i] - '1';
            if (index < 0 || index > 9) {
                continue;
            }
            if (temp[index]++ != 0) {
                return false;
            }
        }
    }
    //3*3验证
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            int temp[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int j = 0; j < 3; ++j) {
                for (int l = 0; l < 3; ++l) {
                    int index = (int) board[k * 3 + j][i * 3 + l] - '1';
                    if (index < 0 || index > 9) {
                        continue;
                    }
                    if (temp[index]++ != 0) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


/**
 * 12 整数转罗马数
 *  执行耗时:24 ms,击败了31.66% 的C++用户
 *  内存消耗:6 MB,击败了81.61% 的C++用户
 * @param num
 * @return
 */
string intToRoman(int num) {
    int numList[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    stringstream buff;
    for (int i = 0; i < 13 && num != 0; ++i) {
        for (int j = 0; j < num / numList[i]; ++j) {
            buff << roman_map(numList[i]);
        }
        num %= numList[i];
    }
    return buff.str();
}

/**
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
 * @param a
 * @return
 */
string roman_map(int n) {
    switch (n) {
        case 1:
            return "I";
        case 4:
            return "IV";
        case 5:
            return "V";
        case 9:
            return "IX";
        case 10:
            return "X";
        case 40:
            return "XL";
        case 50:
            return "L";
        case 90:
            return "XC";
        case 100:
            return "C";
        case 400:
            return "CD";
        case 500:
            return "D";
        case 900:
            return "CM";
        case 1000:
            return "M";
    }
    return "OK";
}


/**
 * x的平方根
 * 二分查找
 * 执行耗时:4 ms,击败了59.28% 的C++用户
 * 内存消耗:5.7 MB,击败了81.35% 的C++用户
 * @param x
 * @return
 */
int mySqrt(int x) {
    if (x == 1) {
        return 1;
    }
    int max = 0;
    int n = x;
    while (n - max > 1) {
        long mid = (max + n) / 2;
        long mid2 = mid * mid;
        if (mid2 == x) {
            return mid;
        }
        if (mid2 > x) {
            n = mid;
        } else {
            max = mid;
        }

    }
    return max;
}

/**
 * 70 爬楼梯
 * 执行耗时:0 ms,击败了100.00% 的C++用户
 * 内存消耗:6 MB,击败了29.57% 的C++用户
 * @param n
 * @return
 */
int climbStairs(int n) {
    int *p = new int[n + 1];
    for (int i = 0; i <= n; ++i) {
        p[i] = 0;
    }
    return climbStairs_help(p, n);
}

int climbStairs_help(int *p, int n) {
    if (p[n] == 0) {
        if (n == 1 || n == 2) {
            return n;
        }
        p[n] = climbStairs_help(p, n - 1) + climbStairs_help(p, n - 2);
    }
    return p[n];
}


/**
 * 67. 两个二进制数求和
 * @param a
 * @param b
 * @return
 */
string addBinary(string a, string b) {
    int n = 0;
    int i = a.length();
    int j = b.length();
    string result;
    while (i > 0 && j > 0) {
        i--;
        j--;
        int intA = a[i] - '0';
        int intB = b[j] - '0';
        int sum = intA + intB + n;
        n = sum / 2;
        result += ('0' + (sum % 2));
    }
    if (i > 0) {
        while (--i >= 0) {
            int intA = a[i] - '0';
            int sum = intA + n;
            n = sum / 2;
            result += ('0' + sum % 2);
        }
    }
    if (j > 0) {
        while (--j >= 0) {
            int intB = b[j] - '0';
            int sum = intB + n;
            n = sum / 2;
            result += ('0' + sum % 2);
        }
    }
    if (n) {
        result += '1';
    }
    return reverse(result, result.length());
}

string reverse(string s, int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

char get_char(char a) {
    switch (a) {
        case '(':
            return ')';
        case '{':
            return '}';
        case '[':
            return ']';
    }
    return ' ';
}

bool isValid(string s) {
    bool flag = true;
    stack<char> sta;
    for (int i = 0; i < s.size(); ++i) {
        char temp = s[i];
        if (temp == '(' || temp == '{' || temp == '[') {
            sta.push(temp);
        } else {
            if (sta.empty()) {
                flag = false;
                break;
            }
            char a = sta.top();
            if (temp != get_char(a)) {
                flag = false;
                break;
            }
            sta.pop();
        }
    }
    if (sta.empty() && flag) {
        return true;
    }
    return false;
}


/**
 * 1. 没有判断是否为空情况
 * 2. 没有判断内容为空的情况
 * 3. 没有判断第一个字符串是否超限的情况
 * @param strs
 * @return
 */
string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
        return "";
    }
    for (int j = 0; j < strs.size(); ++j) {
        if ("" == strs[j]) {
            return "";
        }
    }
    int max = 0;
    string preStr;
    while (strs[0].size() > max) {
        char temp = strs[0][max];
        bool flag = false;
        for (int i = 1; i < strs.size(); ++i) {
            if (temp != strs[i][max]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
        max++;
    }
    return strs[0].substr(0, max);
}

int getValue(char ch) {
    switch (ch) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}


int romanToInt(string s) {
    int front = 0;
    int sum = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        int temp = getValue(s[i]);
        if (temp < front) {
            sum -= temp;
        } else {
            sum += temp;
        }
        front = temp;
    }
    return sum;

}


/**
 * 冒泡
 * @param p
 * @param size
 */
void bubble_sort(int *p, int size) {
    for (int i = size; i > 0; --i) {
        bool flag = true;
        for (int j = 0; j < i - 1; ++j) {
            if (p[j] > p[j + 1]) {
                int n = p[j];
                p[j] = p[j + 1];
                p[j + 1] = n;
                flag = false;
            }
        }
        if (flag) {
            break;
        }
    }
}

/**
 * 插入排序
 * @param p
 * @param size
 */
void insert_sort(int *p, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            if (p[j - 1] > p[j]) {
                int item = p[j - 1];
                p[j - 1] = p[j];
                p[j] = item;
            } else {
                break;
            }
        }
    }
}

/**
 * 归并排序
 * @param p
 * @param size
 */
void merge_sort(int *p, int size) {
    merge_sort_help(p, 0, size);
}

/**
 * 分治函数
 * @param p
 * @param first
 * @param last
 */
void merge_sort_help(int *p, int first, int last) {
    int dt = last - first;
    if (dt == 1 || dt == 0) {
        return;
    }
    int min = (first + last) / 2;
    merge_sort_help(p, first, min);
    merge_sort_help(p, min, last);
    merge(p, first, min, last);

}

/**
 * 合并函数
 * @param p
 * @param first
 * @param min
 * @param last
 */
void merge(int *p, int first, int min, int last) {
    int size = last - first;
    int *k = new int[size];
    int l1 = first;
    int l2 = min;
    for (int i = 0; i < size; ++i) {
        if (l2 == last || (l1 < min && p[l1] < p[l2])) {
            k[i] = p[l1++];
        } else {
            k[i] = p[l2++];
        }
    }
    for (int i = first; i < last; ++i) {
        p[i] = k[i - first];
    }
    delete k;
}


/**
 * 快速排序
 * @param p
 * @param size
 */
void quick_sort(int *p, int size) {
    quick_sort_help(p, 0, size);
}

/**
 * 快排的辅助函数
 * @param p
 * @param first
 * @param last
 */
void quick_sort_help(int *p, int first, int last) {
    if (last - first <= 1) {
        return;
    }
    int pivot = partition(p, first, last - 1);
//    cout << first << '\t' << pivot << '\t' << last << endl;
    quick_sort_help(p, first, pivot);
    quick_sort_help(p, pivot + 1, last);
}

/**
 * 找到数组中首个元素的正确位置 多种方法实现
 * @param p
 * @param first
 * @param last
 * @return
 */
int partition(int *p, int first, int last) {
    int pivot = first;
    while (first < last) {
        while ((first < last) && (p[pivot] <= p[last])) {
            last--;
        }
        if (p[pivot] > p[last]) {
            int n = p[last];
            p[last] = p[pivot];
            p[pivot] = n;
            pivot = last;
            first++;
        }
        while ((first < last) && (p[pivot] >= p[first])) {
            first++;
        }
        if (p[pivot] < p[first]) {
            int n = p[first];
            p[first] = p[pivot];
            p[pivot] = n;
            pivot = first;
            last--;
        }
    }
    return pivot;
}


/**
 *
 * @param s  排序函数
 * @param size 数组的大小
 * @param num 排序几遍
 * @param out 是否打印日志
 */
void statistics_time(mySort s, int size, int num, bool out) {
    //花费的时间
    int sum = 0;
    srand((int) time(0));
    int process = num / 10;
    for (int k = 0; k < num; ++k) {
        //产生随机数
        int *p = new int[size];
        for (int i = 0; i < size; ++i) {
            p[i] = rand() % size;
        }
        //输出日志
        for (int i = 0; i < size && out; ++i) {
            cout << p[i] << ' ';
        }
        if (out) {
            cout << endl;
        }
        //打印时间
        int start = time(NULL);
        s(p, size);
        sum += time(NULL) - start;
        //输出日志
        for (int j = 0; j < size && out; ++j) {
            cout << p[j] << ' ';
        }
        if (out) {
            cout << endl;
        }
        if (k % process == 0) {
            cout << ".";
        }
    }
    //打印时间
    cout << "\n" << sum << endl;
}

int f(int x, int y, int length) {
    int k1 = 1;
    if (y % 2 == 1) {
        k1 = -1;
    }
    return x * k1 + length * ((y + 1) / 2);
}

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    int length = numRows * 2 - 2;
    cout << length << endl;
    int strLength = s.length();
    cout << strLength << endl;
    string result;
    for (int l = 0; l < strLength; l += 2) {
        int index = f(0, l, length);
        if (index >= strLength) {
            break;
        }
        cout << index << '\t';
        result += s[index];
    }
    for (int i = 1; i < numRows - 1; ++i) {
        //定位点
        for (int j = 0; j < strLength; j++) {
            int index = f(i, j, length);
            if (index >= strLength) {
                break;
            }
            cout << index << '\t';
            result += s[index];
        }
    }
    for (int k = 1; k < strLength; k += 2) {
        int index = f(numRows - 1, k, length);
        if (index > strLength) {
            break;
        }
        cout << index << '\t';
        result += s[index];
    }
    return result;
}

int maxLength(vector<vector<char >> &matrix, int i, int j, int temp) {
    int length = matrix.size();
    int width = matrix[0].size();
    if (i + temp >= length || j + temp >= width) {
        return temp;
    }
    bool flag = true;
    for (int k = 0; k < temp + 1; ++k) {
        if (matrix[i + temp][k + j] != '1' || matrix[i + k][j + temp] != '1') {
            flag = false;
            break;
        }
    }
    if (flag) {
        return maxLength(matrix, i, j, temp + 1);
    }
    return temp;
}


int maximalSquare(vector<vector<char >> &matrix) {
    int max = 0;
    int length = matrix.size();
    int width = matrix[0].size();
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            if (matrix[i][j] == '1') {
                int temp = maxLength(matrix, i, j, 1);
                if (temp > max) {
                    max = temp;
                }
            }
        }
    }
    return max;
}

int maxArea(vector<int> &height) {
    int maxNum = 0;
    int front = 0;
    int last = height.size() - 1;
    while (front < last) {
        int h = min(height[front], height[last]);
        int temp = h * (last - front);
//        cout << front << '\t' << last << '\t' << temp << '\n';
        maxNum = max(maxNum, temp);
        if (height[front] < height[last]) {
            front++;
        } else {
            last--;
        }
    }
    return maxNum;
}
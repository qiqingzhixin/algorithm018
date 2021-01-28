//
// Created by Administrator on 2020/11/08.
//

/**
 * 组合
 * @param n
 * @param k
 * @return
 */
vector <vector<int>> combine(int n, int k) {
    vector <vector<int>> result;
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
void combineHelp(vector <vector<int>> &result, vector<int> &temp, int n, int k, int i, int j) {
    if ((n - x) < (k - i)) {
        return;
    }
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
 * 看成选不选的问题
 * 第一步选不选1，第二步选不选2 依次下去
 * @param n
 * @param k
 * @return
 */
vector <vector<int>> combine2(int n, int k) {
    vector <vector<int>> result;
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
void combine2Help(vector <vector<int>> &result, vector<int> &temp, int n, int k, int i) {
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
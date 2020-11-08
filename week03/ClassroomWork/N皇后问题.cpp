//
// Created by Administrator on 2020/11/08.
//
/**
 *执行耗时:8 ms,击败了88.43% 的C++用户
 *内存消耗:8.3 MB,击败了33.18% 的C++用户
 * 一开始使用的是set 后来改成数组快了不少
 * 优化的生成字符串的方式，一开始先是生成vector<vector<int>> 类型的，然后在一起转化成vector<vector<string>> ,现在优化成直接生成vector<vector<string>>
 * 和解数独有异曲同工之妙
 * @param n
 * @return
 */
vector <vector<string>> solveNQueens(int n) {
    vector <vector<string>> result;
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
NQueensHelp(vector <vector<string>> &result, vector<int> &temp, int *lie, int *na, int *pie, int n,
            int k) {
    if (n == k) {
        vector <string> item;
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
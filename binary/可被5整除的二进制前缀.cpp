//
// Created by Administrator on 2021/01/27.
//

/**
 * 可被5整除的二进制前缀
 */
vector<bool> prefixesDivBy5(vector<int> &A) {
    int n = 0;
    vector<bool> result;
    for (int i = 0; i < A.size(); ++i) {
        n = n * 2 + A[i];
        result.push_back(n % 5 == 0);
    }
    return result;
}
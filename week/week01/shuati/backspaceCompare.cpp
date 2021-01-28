//
// Created by Administrator on 2020/10/20.
//


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        //代表有效字符串的个数
        int s_index = 0;
        int t_index = 0;
        bool flag = true;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != '#') {
                //有效的情况
                S[s_index++] = S[i];
            } else if (s_index > 0) {
                //进行回退并且可以回退
                s_index--;
            }
        }
        for (int j = 0; j < T.length(); ++j) {
            if (T[j] != '#') {
                T[t_index++] = T[j];
            } else if (t_index > 0) {
                t_index--;
            }
        }
        //比较两个字符串长度是否相等
        if (s_index != t_index) {
            return false;
        }
        //比较两个字符串的内容是否相等
        for (int k = 0; k < s_index; ++k) {
            if (S[k] != T[k]) {
                return false;
            }
        }
        return true;
    }
};
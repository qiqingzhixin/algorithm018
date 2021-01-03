//
// Created by Administrator on 2020/12/28.
//
string reverseStr(string s, int k) {
    int len = s.size();
    for (int i = 0; i < len; i += 2 * k) {
        if (i + k < len) {
            reverseStrHelp(s, i, i + k - 1);
        } else {
            reverseStrHelp(s, i, len - 1);
        }
    }
    return s;
}

/**
 * 反转指定字符串
 * @param s 字符串
 * @param l 反转的开始
 * @param r 反转的结束
 */
void reverseStrHelp(string &s, int l, int r) {
    while (l < r) {
        char a = s[l];
        s[l] = s[r];
        s[r] = a;
        l++;
        r--;
    }
}
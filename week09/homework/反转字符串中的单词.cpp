//
// Created by Administrator on 2020/12/28.
//
string reverseWords(string s) {
    int len = s.size();
    int start = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            reverseStrHelp(s, start, i - 1);
            start = i + 1;
        }
    }
    reverseStrHelp(s, start, len - 1);
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
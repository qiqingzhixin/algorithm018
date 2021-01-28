//
// Created by Administrator on 2020/11/29.
//

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
 * 可以通过斐波那契数列进行优化
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
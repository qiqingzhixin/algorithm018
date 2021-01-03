//
// Created by Administrator on 2020/12/28.
//
string reverseWords(string s) {
    int index = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            if (index == 0) {
                continue;
            } else if (s[index - 1] == ' ') {
                continue;
            }
        }
        s[index] = s[i];
        index++;
    }
    s.erase(s[index - 1] == ' ' ? index - 1 : index);

    int len = s.size();
    cout << len << endl;
    reverseStrHelp(s, 0, len - 1);
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
void reverseStrHelp(string &s, int l, int r) {
    while (l < r) {
        char a = s[l];
        s[l] = s[r];
        s[r] = a;
        l++;
        r--;
    }
}
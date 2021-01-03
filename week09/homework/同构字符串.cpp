//
// Created by Administrator on 2020/12/28.
//
bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    int counts[2][255]{{0}};
    for (int i = 0; i < s.size(); ++i) {
        if (counts[0][s[i]] == 0 && counts[1][t[i]] == 0) {
            counts[0][s[i]] = t[i];
            counts[1][t[i]] = s[i];
            continue;
        } else if (counts[0][s[i]] != t[i] || counts[1][t[i]] != s[i]) {
            return false;
        }
    }
    return true;
}
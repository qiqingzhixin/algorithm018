//
// Created by Administrator on 2020/10/31.
//

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
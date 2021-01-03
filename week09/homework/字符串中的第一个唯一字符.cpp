//
// Created by Administrator on 2020/12/28.
//
int firstUniqChar(string s) {
    if (s.size() == 0) {
        return -1;
    }
    int map[26]{0};
    for (int i = 0; i < s.size(); ++i) {
        int index = s[i] - 'a';
        if (map[index] == 0) {
            map[index] = i + 1;
        } else {
            map[index] = -1;
        }
    }
    int minIndex = s.size() + 2;
    for (int i = 0; i < 26; ++i) {
        if (map[i] > 0 && map[i] < minIndex) {
            minIndex = map[i];
        }
    }
    return minIndex > s.size() ? -1 : (minIndex - 1);
}
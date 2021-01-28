//
// Created by Administrator on 2021/01/27.
//

/**
 * 较大分组的位置
 *
 * abcdddeeeeaabbbcd
 * @param s
 * @return
 */
vector<vector<int>> largeGroupPositions(string s) {
    if (s.size() < 3) {
        return {};
    }
    vector<vector<int>> result;
    int len = 1;
    int meetLen = 3;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == s[i]) {
            len++;
            continue;
        } else if (len >= meetLen) {
            result.push_back({i - len, i - 1});
        }
        len = 1;
    }
    if (len >= meetLen) {
        result.push_back({int(s.size() - len), int(s.size() - 1)});
    }
    return result;
}

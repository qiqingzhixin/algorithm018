//
// Created by Administrator on 2020/12/06.
//

/**
 * 76.最小覆盖子串
 * @param s
 * @param t
 * @return
 */
string minWindow(string s, string t) {
    if (t == "" || s == "") {
        return "";
    }
    //汉明距离
    int distance = t.size();
    unordered_map<char, int> sMap, tMap;
    for (int i = 0; i < t.size(); ++i) {
        if (tMap.count(t[i]) == 0) {
            tMap[t[i]] = 1;
            sMap[t[i]] = 0;
        } else {
            tMap[t[i]]++;
        }
    }
    int left = 0, right = 0, min = s.size() + 1;
    int minLeft = 0;
    while (right < s.size()) {
        if (tMap.count(s[right]) != 0) {
            sMap[s[right]]++;
            //如果有且没有超过汉明距离-1
            if (sMap[s[right]] <= tMap[s[right]]) {
                distance--;
                //没有了汉明距离
                while (distance == 0) {
                    if (min > (right - left + 1)) {
                        min = right - left + 1;
                        minLeft = left;
                    }
                    if (tMap.count(s[left]) != 0) {
                        sMap[s[left]]--;
                        //如果窗口的字符不满足需要的汉明距离+1
                        if (sMap[s[left]] < tMap[s[left]]) {
                            distance++;
                        }
                    }
                    //指向下一个
                    left++;
                }
            }
        }
        right++;
    }
    //说明没有匹配上
    if (min == s.size() + 1) {
        return "";
    }
    return s.substr(minLeft, min);
}
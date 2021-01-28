//
// Created by Administrator on 2020/10/31.
//

/**
 * 排序原字符串 根据排序后的字符串作为key值，原字符串作为value值
 * @param strs
 * @return
 */
vector <vector<string>> groupAnagrams(vector <string> &strs) {
    map <string, vector<string>> result;
    for (int i = 0; i < strs.size(); ++i) {
        string deal_string = strs[i];
        sort(deal_string.begin(), deal_string.end());
        result[deal_string].push_back(strs[i]);
    }
    vector <vector<string>> res;
    map < string, vector < string >> ::iterator
    item;
    for (item = result.begin(); item != result.end(); item++) {
        res.push_back(item->second);
    }
    return res;
}
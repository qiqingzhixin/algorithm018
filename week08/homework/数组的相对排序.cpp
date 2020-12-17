//
// Created by Administrator on 2020/12/12.
//

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> set;
    unordered_map<int, int> map;
    vector<int> other;
    for (int i = 0; i < arr2.size(); ++i) {
        set.insert(arr2[i]);
    }
    for (int i = 0; i < arr1.size(); ++i) {
        if (set.count(arr1[i])) {
            if (map.count(arr1[i])) {
                map[arr1[i]]++;
            } else {
                map[arr1[i]] = 1;
            }
        } else {
            other.push_back(arr1[i]);
        }
    }
    sort(other.begin(), other.end(), [](int i, int j) { return i < j; });
    vector<int> result;
    for (int j = 0; j < arr2.size(); ++j) {
        if (map.count(arr2[j])) {
            for (int i = 0; i < map[arr2[j]]; ++i) {
                result.push_back(arr2[j]);
            }
        }
    }
    result.insert(result.end(), other.begin(), other.end());
    return result;
}
//
// Created by Administrator on 2020/11/01.
//

vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> countMap;
    for (int i = 0; i < nums.size(); ++i) {
        if (countMap.count(nums[i]) == 0) {
            countMap[nums[i]] = 1;
        } else {
            countMap[nums[i]]++;
        }
    }
    priority_queue <pair<int, int>> q;
    map<int, int>::iterator iterator = countMap.begin();
    while (iterator != countMap.end()) {
        q.push(pair<int, int>(iterator->second, iterator->first));
        iterator++;
    }
    vector<int> result;
    for (int j = 0; j < k; ++j) {
        result.push_back(q.top().second);
        q.pop();
    }
    return result;
}
//
// Created by Administrator on 2020/10/31.
//

/**
 * 两个数之和
 * 1. 暴力方法
 * 2. 排序加双指针
 * 3. hash表
 */

vector<int> twoSum2(vector<int> &nums, int target) {
    //排序
    sort(nums.begin(), nums.end());
    vector<int> result;
    //双指针
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

vector<int> twoSum2HashTable(vector<int> &nums, int target) {
    //创建一个hash表
    unordered_map<int, int> table;

    for (int i = 0; i < nums.size(); ++i) {
        //查询是否有对应的值
        auto item = table.find(target - nums[i]);
        //如果有就返回
        if (item != table.end()) {
            return {item->second, i};
        }
        //如果没有就添加到hash表中
        table[nums[i]] = i;
    }
}

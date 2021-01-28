//
// Created by Administrator on 2020/10/21.
//

/**
 * 两个数之和
 */
vector<int> twoSum(vector<int>& nums, int target) {
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
    return{};
}
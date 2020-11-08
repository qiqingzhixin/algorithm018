//
// Created by Administrator on 2020/11/08.
//

/**
 * 执行耗时:4 ms,击败了89.26% 的C++用户
			内存消耗:7.8 MB,击败了31.29% 的C++用户
 * @param nums
 * @return
 */
vector <vector<int>> permute(vector<int> &nums) {
    vector <vector<int>> result;
    permute2Help(result, nums, 0);
    return result;
}

/**
 * 第几个数和后面的数进行交换
 * @param result
 * @param nums
 * @param k
 */
void permute2Help(vector <vector<int>> &result, vector<int> &nums, int k) {
    if (k == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    for (int i = k; i < nums.size(); ++i) {
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
        permute2Help(result, nums, k + 1);
        temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
}
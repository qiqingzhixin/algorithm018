//
// Created by Administrator on 2020/11/15.
//

/**
 * 贪心算法
 * @param nums
 * @return
 */
bool canJump(vector<int> &nums) {
    int max = 0;
    for (int i = 0; i < nums.size() && i <= max; ++i) {
        if (max >= nums.size() - 1) {
            return true;
        }
        if (max < i + nums[i]) {
            max = i + nums[i];
        }
    }
    return false;
}


/**
 * [55]跳跃游戏 使用动态规划，超时了
 * @param nums
 * @return
 */
bool canJump1(vector<int> &nums) {
    return canJump(nums, 0);
}

bool canJump(vector<int> &nums, int index) {
    int max = nums[index];
    if (index + max >= nums.size() - 1) {
        return true;
    }
    for (int i = 1; i <= max; ++i) {
        if (canJump(nums, index + i)) {
            return true;
        }
    }
    return false;
}
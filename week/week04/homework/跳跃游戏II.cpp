//
// Created by Administrator on 2020/11/15.
//

/**
 * 贪心算法
 * @param nums
 * @return
 */
int jump(vector<int> &nums) {
    int max = 0;
    int step = 0;
    int end = 0;
    int length = nums.size() - 1;
    for (int i = 0; i < length; ++i) {
        if (max < i + nums[i]) {
            max = i + nums[i];
            if (max >= length) {
                return step + 1;
            }
        }
        if (i == end) {
            end = max;
            step++;
        }
    }
    return step;
}

/**
 * 动态规划 这个实在学校学的。
 * @param nums
 * @return
 */
int jumpDT(vector<int> &nums) {
    if (nums.size() <= 1) {
        return 0;
    }
    int *minStep = new int[nums.size()];
    for (int i = 0; i < nums.size(); ++i) {
        minStep[i] = -1;
    }
    return jumpHelp(nums, 0, minStep);
}

int jumpHelp(vector<int> &nums, int index, int *minStep) {
    //最后一跳
    if (nums[index] + index >= nums.size() - 1) {
        return 1;
    }
    //这一跳的范围
    int min = -1;
    for (int i = 1; i <= nums[index]; ++i) {
        int temp = minStep[i + index] != -1 ? minStep[i + index] : jumpHelp(nums, index + i, minStep);
        if (temp != 0 && (min == -1 || min > temp)) {
            min = temp;
        }
    }
    minStep[index] = min + 1;
    return min + 1;
}
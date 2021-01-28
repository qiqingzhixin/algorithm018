//
// Created by Administrator on 2020/11/15.
//

/**
 * 寻找旋转数组的最小值
 * @param nums
 * @return
 */
int findMin(vector<int> &nums) {
    //没有旋转的情况
    if (nums[0] < nums[nums.size() - 1]) {
        return nums[0];
    }
    //旋转的情况
    int start = 0;
    int end = nums.size() - 1;
    int min;
    while (end - start > 1) {
        min = (start + end) / 2;
        if (nums[start] < nums[min]) {
            start = min;
        } else {
            end = min;
        }
    }
    return nums[end];
}
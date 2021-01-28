//
// Created by Administrator on 2021/01/27.
//


/**
 * 330.按照要求补齐数组
 * @param nums
 * @param n
 * @return
 */
int minPatches(vector<int> &nums, int n) {
    //需要的最大数字
    long maxFar = 1;
    //添加了几个数
    int dispatch = 0;
    //坐标的位置
    int index = 0;

    int len = nums.size();
    while (maxFar <= n) {
        if (index < len && nums[index] <= maxFar) {
            maxFar += nums[index];
            index++;
        } else {
            //放入一个需要的数
            maxFar *= 2;
            dispatch++;
        }
    }
    return dispatch;
}


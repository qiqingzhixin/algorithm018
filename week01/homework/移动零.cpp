//
// Created by Administrator on 2020/10/25.
//

void moveZeroes(vector<int>& nums) {
    int size = nums.size();
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] != 0) {
            nums[index++] = nums[i];
        }
    }
    for (; index < size; ++index) {
        nums[index] = 0;
    }
}
//
// Created by Administrator on 2020/10/24.
//

int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    int id = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[id] != nums[i]) {
            nums[++id]=nums[i];
        }
    }
    return id+1;
}

int removeDuplicates2(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        //第一个就赋值，如果nums[i-1]小于n说明发生了变化就赋值
        if (!i || n > nums[i-1])
            nums[i++] = n;
    return i;
}
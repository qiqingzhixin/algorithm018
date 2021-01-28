//
// Created by Administrator on 2020/10/25.
//

void rotate(vector<int>& nums, int k) {
    //存放临时数据
    int temp = nums[0];
    //数组长度
    int size = nums.size();
    //交换了多少次
    int count = 0;
    //每轮第一次的坐标是多少
    int firstIndex = 0;
    //交换坐标
    int index = 0;
    //交换后的下一个位置
    int next = 0;
    while (count < size) {
        next = (index + k) % size;
        if (firstIndex == next) {
            nums[firstIndex] = temp;
            count++;
            firstIndex = (firstIndex + 1) % size;
            index = firstIndex;
            temp = nums[index];
            continue;
        }
        int n = nums[next];
        nums[next] = temp;
        temp = n;
        index = next;
        count++;
    }
}
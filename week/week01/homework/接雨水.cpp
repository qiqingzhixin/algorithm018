//
// Created by Administrator on 2020/10/25.
//

int trap(vector<int> &height) {
    int sum = 0;
    int left = 0;
    int left_max = 0;
    int right = height.size() - 1;
    int right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > left_max) {
                left_max = height[left];
            } else {
                sum += (left_max - height[left]);
            }
            left++;
        } else {
            if (height[right] > right_max) {
                right_max = height[right];
            } else {
                sum += (right_max - height[right]);
            }
            right--;
        }
    }
    return sum;
}
//
// Created by Administrator on 2020/10/25.
//

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int resultIndex = m + n - 1;
    int index1 = m - 1;
    int index2 = n - 1;
    while (index1 >= 0 && index2 >= 0) {
        if (nums1[index1] > nums2[index2]) {
            nums1[resultIndex--] = nums1[index1--];
        } else {
            nums1[resultIndex--] = nums2[index2--];
        }
    }
    while (index2 >= 0) {
        nums1[resultIndex--] = nums2[index2--];
    }
}
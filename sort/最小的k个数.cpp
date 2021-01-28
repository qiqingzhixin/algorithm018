//
// Created by Administrator on 2021/01/27.
//

/**
 *
 * @param arr
 * @param k
 * @return
 */
vector<int> smallestK(vector<int> &arr, int k) {
    if (k == 0) {
        return {};
    }
    int start = 0;
    int end = arr.size();
    while (true) {
        int n = smallestKHelp(arr, start, end);
        if (n < k) {
            start = n + 1;
        } else if (n > k) {
            end = n - 1;
        } else {
            break;
        }
    }
    vector<int> result(arr.begin(), arr.begin() + k);
    return result;
}

int smallestKHelp(vector<int> &arr, int start, int end) {
    int left = start;
    int right = end;
    int tar = arr[left];
    while (left < right) {
        while (left < right && tar < arr[right]) {
            right--;
        }
        arr[left++] = arr[right];
        while (left < right && arr[left] < tar) {
            left++;
        }
        arr[right--] = arr[left];
    }
    arr[left] = tar;
    return left;
}
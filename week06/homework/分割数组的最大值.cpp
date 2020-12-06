//
// Created by Administrator on 2020/12/05.
//

/**
 * 动态规划
 * @param nums
 * @param m
 * @return
 */
int splitArray2(vector<int> &nums, int m) {
    int n = nums.size();
    vector <vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
    vector<long long> sub(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sub[i + 1] = sub[i] + nums[i];
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, m); j++) {
            for (int k = 0; k < i; k++) {
                f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
            }
        }
    }
    return (int) f[n][m];

}

/**
 *
 * 分割数组的最大值
 * 使用动态规划 内存优化
 * @param nums
 * @param m
 * @return
 */
int splitArray(vector<int> &nums, int m) {
    if (nums.size() == 0 && m == 0) {
        return 0;
    }
    // 0代表偶数，1代表奇数,2 代表0-i所有数之和
    int **p = new int *[3];
    for (int i = 0; i < 3; ++i) {
        p[i] = new int[nums.size()];
    }
    p[1][0] = nums[0];
    //方便计算任意一段的数值
    p[2][0] = nums[0];
    p[0][0] = INT32_MAX;
    //初始化 也代表分成1段的情况 段的最大值中的最小值
    for (int i = 1; i < nums.size(); ++i) {
        p[1][i] = nums[i] + p[1][i - 1];
        p[2][i] = nums[i] + p[2][i - 1];
        p[0][i] = INT32_MAX;
    }
    //m:代表分成m段
    for (int i = 2; i <= m; ++i) {
        //最大坐标为;
        for (int n = i - 1; n < nums.size(); ++n) {
            // 看成 前j个数分成i-1段 最后一段的取值为j+1,nums.size();
            for (int j = i - 2; j < n; ++j) {
                //这个状态 第一个数 = 之前的状状态值（肯定大于现在的状态 因为相同的数，分的份数变多，所以分的份数大的最大值一定小于等于分的份数少的最大值),
                // 上一个状态 分成i-1 段中包含了j-1 个数，最后一段 包含了 nums.size()-j个数
                p[i % 2][n] = min(p[i % 2][n], max(p[(i - 1) % 2][j], p[2][n] - p[2][j]));
            }
        }
    }
    return p[m % 2][nums.size() - 1];
}

/**
 * 首先能确定最大值的取值范围 在[max(nums),sum[nums]] 范围
 * 如果我在这个里面取一个值 l，然后让每一个子段不能大于这个值，看看能分成k，如果k>m ,说明l取小了，如果k<=m 有可能取大了 知道所有数试一遍
 * 这里可以使用二分查找来加速搜索。
 * @param nums
 * @param m
 * @return
 */
int splitArray3(vector<int> &nums, int m) {
    //数组中最大的值，数组之和
    int left = nums[0], right = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (left < nums[i]) {
            left = nums[i];
        }
        right += nums[i];
    }
    //初始化最小值
    int min = right;
    while (left <= right) {
        //取中间的值
        int mid = (left + right) / 2;
        int validNum = validIsOK(nums, m, mid);
        if (validNum == 1) {
            if (min > mid) {
                min = mid;
            }
            right = mid - 1;
        } else if (validNum == -1) {
            left = mid + 1;
        }
    }
    return min;
}

/**
 *
 * @param nums
 * @param m 要分成分成多少段
 * @param n 每一段的最大值
 * @return -1 代表n取小了，1 有可能合适
 */
int validIsOK(vector<int> &nums, int m, int n) {
    //分了多少段
    int count = 1;
    int temp = 0;
    for (int i = 0; i < nums.size(); ++i) {
        temp += nums[i];
        //超了
        if (temp > n) {
            temp = nums[i];
            count++;
        }
    }
    if (count > m) {
        return -1;
    }
    return 1;
}
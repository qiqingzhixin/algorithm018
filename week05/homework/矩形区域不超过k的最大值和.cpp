//
// Created by Administrator on 2020/12/03.
//

/**
 * 固定左右边界
 * @param matrix
 * @param k
 * @return
 */
int maxSumSubmatrix4(vector<vector<int>> &matrix, int k) {
    int length = matrix.size();
    int weight = matrix[0].size();
    int max = INT32_MIN;
    for (int left = 0; left < weight; ++left) {
        int *p = new int[length]{0};
        for (int right = left; right < weight; ++right) {
            for (int i = 0; i < length; ++i) {
                p[i] += matrix[i][right];
            }
            //取数组的中和最大的
            for (int i = 0; i < length; ++i) {
                int sum = 0;
                for (int j = i; j < length; ++j) {
                    sum += p[j];
                    if (sum > max && sum <= k) {
                        max = sum;
                    }
                }
            }
        }
    }
    return max;
}

/**
 * 减少内存
 * @param matrix
 * @param k
 * @return
 */
int maxSumSubmatrix3(vector<vector<int>> &matrix, int k) {
    int length = matrix.size();
    int weight = matrix[0].size();
    int max = INT32_MIN;
    for (int i = 1; i <= length; ++i) {
        for (int j = 1; j <= weight; ++j) {
            int **p = new int *[length + 1];
            for (int i = 0; i < length + 1; ++i) {
                p[i] = new int[weight + 1]{0};
            }
            for (int iEnd = i; iEnd <= length; ++iEnd) {
                for (int jEnd = j; jEnd <= weight; ++jEnd) {
                    p[iEnd][jEnd] =
                            p[iEnd - 1][jEnd] + p[iEnd][jEnd - 1] - p[iEnd - 1][jEnd - 1] + matrix[iEnd - 1][jEnd - 1];
                    if (p[iEnd][jEnd] > max && p[iEnd][jEnd] <= k) {
                        max = p[iEnd][jEnd];
                    }
                }
            }
        }
    }
    return max;
}

/**
 * 363 给定一个非空二维矩阵 matrix 和一个整数 k，找到这个矩阵内部不大于 k 的最大矩形和
 * 当宽度和高度都为1 ok
 *
 * f(iStart,jStart,iEnd,jEnd)=f(iStart,jStart,iEnd-1,jEnd-i)+f(iEnd-1,jStart,iEnd,jEnd-1)+f(iStart,jEnd-1,iEnd-1,jEnd)+f(iEnd,jEnd,iEnd,jEnd)
 * @param matrix
 * @param k
 * @return
 */
int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int length = matrix.size();
    int weight = matrix[0].size();
    int max = INT32_MIN;
    int ****p = new int ***[length];
    for (int i = 0; i < length; ++i) {
        p[i] = new int **[weight];
        for (int j = 0; j < weight; ++j) {
            p[i][j] = new int *[length];
            for (int l = 0; l < length; ++l) {
                p[i][j][l] = new int[weight];
            }
        }
    }
    //宽度
    for (int iLength = 1; iLength <= length; ++iLength) {
        for (int jWeight = 1; jWeight <= weight; ++jWeight) {
            for (int i = 0; i <= length - iLength; ++i) {
                for (int j = 0; j <= weight - jWeight; ++j) {
                    int iEnd = i + iLength - 1;
                    int jEnd = j + jWeight - 1;
                    if (i == iEnd && j == jEnd) {
                        // 一个元素
                        p[i][j][i][j] = matrix[i][j];
                    } else if (i == iEnd) {
                        //一行元素
                        p[i][j][i][jEnd] = p[i][j][i][jEnd - 1] + p[i][jEnd][i][jEnd];
                    } else if (j == jEnd) {
                        //一列元素
                        p[i][j][iEnd][j] = p[i][j][iEnd - 1][j] + p[iEnd][j][iEnd][j];
                    } else {
                        //多行多列
                        p[i][j][iEnd][jEnd] = p[i][j][iEnd - 1][jEnd - 1] + p[iEnd][j][iEnd][jEnd - 1] +
                                              p[i][jEnd][iEnd - 1][jEnd] + p[iEnd][jEnd][iEnd][jEnd];
                    }
                    if (p[i][j][iEnd][jEnd] <= k && p[i][j][iEnd][jEnd] > max) {
                        max = p[i][j][iEnd][jEnd];
                    }
                }
            }
        }
    }
    return max;
}
//
// Created by Administrator on 2020/11/30.
//

/**
 * 暴力方法
 * @param matrix
 * @return
 */
int maximalSquare_todo(vector <vector<char>> &matrix) {
    int max = 0;
    int length = matrix.size();
    int weight = matrix[0].size();
    for (int i = 0; i < length; ++i) {
        bool *p = new bool[weight]{false};
        for (int len = 0; i + len < length; ++len) {
            for (int j = 0; j < weight; ++j) {
                if (p[j] == false && matrix[i + len][j] == '0') {
                    p[j] = true;
                }
            }
            int w = 0;
            for (int k = 0; k < weight; ++k) {
                if (p[k] == false) {
                    w++;
                    if (w == len + 1 && len + 1 > max) {
                        max = len + 1;
                        break;
                    }
                } else {
                    w = 0;
                }
            }
        }
    }
    return max * max;
}

/**
 * 采用动态规划
 * 时间复杂度O(mn)
 * 空间复杂度O(n)
 * @param matrix
 * @return
 */
int maximalSquare_2(vector <vector<char>> &matrix) {
    int max = 0;
    int length = matrix.size();
    if (length == 0) {
        return max;
    }
    int weight = matrix[0].size();
    if (weight == 0) {
        return max;
    }
    int *p = new int[weight]{0};
    for (int i = 0; i < length; ++i) {
        int temp = p[0];
        if (matrix[i][0] == '1') {
            p[0] = 1;
            if (p[0] > max) {
                max = 1;
            }
        } else {
            temp = p[0];
            p[0] = 0;
        }
        for (int j = 1; j < weight; ++j) {
            if (matrix[i][j] == '1') {
                int min = threeMin(p[j], p[j - 1], temp);
                temp = p[j];
                p[j] = min + 1;
                if (p[j] > max) {
                    max = p[j];
                }
            } else {
                temp = p[j];
                p[j] = 0;
            }
        }

    }
    return max * max;
}

int threeMin(int n, int m, int k) {
    int min = n;
    if (min > m) {
        min = m;
    }
    if (min > k) {
        min = k;
    }
    return min;
}
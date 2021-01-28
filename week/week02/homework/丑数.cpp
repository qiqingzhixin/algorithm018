//
// Created by Administrator on 2020/10/31.
//

/**
 * 动态规划
 * @param n
 * @return
 */

int nthUglyNumber(int n) {
    vector<int> temp;
    temp.push_back(1);
    int var[] = {0, 0, 0};
    for (int i = 1; i < n; ++i) {
        int num[3];
        num[0] = temp[var[0]] * 2;
        num[1] = temp[var[1]] * 3;
        num[2] = temp[var[2]] * 5;
        int min = num[0] < num[1] ? (num[0] < num[2] ? num[0] : num[2]) : (num[1] < num[2] ? num[1] : num[2]);
        temp.push_back(min);
        for (int j = 0; j < 3; ++j) {
            if (num[j] == min) {
                var[j]++;
            }
        }
    }
    return temp.back();
}
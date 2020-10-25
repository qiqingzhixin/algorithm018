//
// Created by Administrator on 2020/10/20.
//

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int k1 = 1;
    int k2 = 2;
    int temp;
    for (int i = 3; i <= n; ++i) {
        temp = k2;
        k2 += k1;
        k1 = temp;
    }
    return k2;
}
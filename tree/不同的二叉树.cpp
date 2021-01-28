//
// Created by Administrator on 2021/01/27.
//

int numTrees(int n) {
    int *p = new int[n + 1]{0};
    p[0] = 1;
    p[1] = 1;
    int sons;
    for (int i = 2; i <= n; ++i) {
        sons = i - 1;
        for (int left = 0; left < i; ++left) {
            p[i] += p[left] * p[sons - left];
        }
    }
    return p[n];
}
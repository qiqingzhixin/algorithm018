//
// Created by Administrator on 2020/12/08.
//

/**
 * 爬楼梯
 * f(n)=f(n-1)+f(n-2);
 * @param n
 * @return
 */
int climbStairs4(int n) {
    long pref = 1;
    long next = 2;
    for (int i = 1; i < n; ++i) {
        next = pref + next;
        pref = next - pref;
    }
    return pref;
}
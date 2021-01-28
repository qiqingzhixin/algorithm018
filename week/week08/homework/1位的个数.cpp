//
// Created by Administrator on 2020/12/12.
//


/**
 * 191. 位1 个数
 * @param n
 * @return
 */
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        count++;
        n = n & (n - 1);
    }
    return count;
}
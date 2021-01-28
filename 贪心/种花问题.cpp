//
// Created by Administrator on 2021/01/27.
//

/**
 * 650.种花问题
 * @param flowerbed
 * @param n
 * @return
 */
bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int count = 0;
    //种上一个位置
    int len = 1;
    for (int i = 0; i < flowerbed.size(); ++i) {
        if (flowerbed[i] == 0) {
            len++;
        } else {
            count += (len - 1) / 2;
            len = 0;
        }
    }
    count += len / 2;
    return count >= n;
}
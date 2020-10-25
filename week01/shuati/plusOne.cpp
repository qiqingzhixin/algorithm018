//
// Created by Administrator on 2020/10/20.
//
/**
 * 加一
 * @param digits
 * @return
 */
vector<int> plusOne(vector<int> &digits) {
    int n = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
        n += digits[i];
        digits[i] = n % 10;
        n /= 10;
        if (n == 0) {
            break;
        }
    }
    if (n == 1) {
        digits.insert(digits.begin(), n);
    }

    return digits;
}
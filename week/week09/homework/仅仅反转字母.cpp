//
// Created by Administrator on 2020/12/28.
//
string reverseOnlyLetters(string S) {
    int left = 0;
    int right = S.size() - 1;
    while (left < right) {
        if (!isalpha(S[left])) {
            left++;
            continue;
        }
        if (!isalpha(S[right])) {
            right--;
            continue;
        }
        char temp = S[left];
        S[left] = S[right];
        S[right] = temp;
        left++;
        right--;
    }
    return S;
}
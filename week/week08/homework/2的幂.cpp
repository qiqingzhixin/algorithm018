//
// Created by Administrator on 2020/12/12.
//

bool isPowerOfTwo(int n) {
    if(n<=0){
        return false;
    }
    return (n & (n - 1)) == 0;
}
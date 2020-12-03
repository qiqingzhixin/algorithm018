//
// Created by Administrator on 2020/12/01.
//

/**
 * 根据长度来进行dp，这个可以优化内存
 * f(len,index) = true,len=1
 * f(len,index) = s[index]==s[index+1] ,len=2;
 * f(len,index) = s[index]==s[index+len] && f(len-2,index+1) ,len>2
 * @param s
 * @return
 */
int countSubstrings(string s) {
    int length = s.size();
    if (length <= 1) {
        return length;
    }
    int count = length;
    bool **p = new bool *[length];
    for (int j = 0; j < length; ++j) {
        p[j] = new bool[length]{false};
    }
    //len==1
    for (int i = 0; i < length; ++i) {
        p[0][i] = true;
    }
    //len==2
    for (int k = 0; k < length - 1; ++k) {
        if (s[k] == s[k + 1]) {
            p[1][k] = true;
            count++;
        }
    }
    //len > 2
    for (int m = 2; m < length; ++m) {
        for (int l = 0; l < length - m; ++l) {
            if (s[l] == s[l + m] && p[m - 2][l + 1]) {
                p[m][l] = true;
                count++;
            }
        }
    }
    return count++;
}

/**
 * 优化了一些内存(n)
 * @param s
 * @return
 */
int countSubstrings2(string s) {
    int length = s.size();
    if (length <= 1) {
        return length;
    }
    int count = length;
    bool **p = new bool *[2];
    p[0] = new bool[length];
    p[1] = new bool[length];
    //len=1;
    for (int i = 0; i < length; ++i) {
        p[0][i] = true;
    }
    //len=2
    for (int i = 0; i < length - 1; ++i) {
        count += (p[1][i] = s[i] == s[i + 1]);
    }
    for (int i = 2; i < length; ++i) {
        for (int j = 0; j < length - i; ++j) {
            count += (p[i % 2][j] = (s[j] == s[j + i] && p[i % 2][j + 1]));
        }
    }
    return count;
}

/**
 * 官网解法 使用for循环
 * 通过确定左右边界向外扩展方式
 * 时间复杂度 n*n
 * 空间复杂度 1
 * @param s
 * @return
 */
int countSubstrings3(string s) {
    int count = 0;
    int size = s.size();
    int length = s.size() * 2 - 1;
    int l, r;
    for (int i = 0; i < length; ++i) {
        l = i / 2;
        r = (i + 1) / 2;
        while (l >= 0 && r < size && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
    }
    return count;
}

/**
 * manache 算法
 * @param s
 * @return
 */
int countSubstrings(string s) {
    string dealS = "$#";
    for (int j = 0; j < s.size(); ++j) {
        dealS = dealS + s[j] + "#";
    }
    int length = dealS.size();
    dealS = dealS + "!";
    //记录有多少个字串
    int count = 0;
    //记录最右边的回文序列边界
    int maxRight = 0;
    //记录最右边的回文序列边界中心位置
    int maxRightIndex = 0;
    //记录状态的数组
    int *f = new int[dealS.size()]{0};
    for (int i = 1; i < length; ++i) {
        if (i <= maxRight) {
            // i关于maxRightIndex 对称坐标
            int j = maxRightIndex * 2 - i;
            //与最右端的最大距离
            int dx = maxRight - i + 1;
            //不能超过最右端
            f[i] = f[j] > dx ? dx : f[j];
        } else {
            f[i] = 1;
        }
        //中心扩展
        while (dealS[i - f[i]] == dealS[i + f[i]]) {
            f[i]++;
        }
        // 更新数据
        if (i + f[i] - 1 > maxRight) {
            maxRightIndex = i;
            maxRight = f[i] + i - 1;
        }
        // 累加字串数
        count += (f[i] / 2);
    }
    return count;
}
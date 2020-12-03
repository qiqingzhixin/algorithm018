//
// Created by Administrator on 2020/12/03.
//

/**
 * 72.编辑距离
 * 由他人分析可得
 * 操作可以有
 * word1 插入一个字符
 * word2 插入一个字符
 * word1 替换一个字符
 * p[word1.size+1][word2.size+1]={0};
 * 最后一个字母相同
 *  p[i][j]=min(p[i-1][j]+1,p[i][j-1]+1,p[i-1][j-1])
 * 最后一个字母不同
 *  p[i][j]=min(p[i-1][j]+1,p[i][j-1]+1,p[i-1][j-1]+1)=1+min(p[i-1][j],p[i][j-1],p[ji-1][j-1]);
 *
 * 同样这里可以优化成一维数组。
 *
 * @param word1
 * @param word2
 * @return
 */
int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    int **p = new int *[len1 + 1];
    for (int i = 0; i <= len1; ++i) {
        p[i] = new int[len2 + 1];
    }
    //初始化
    for (int j = 0; j <= len1; ++j) {
        p[j][0] = j;
    }
    for (int j = 1; j <= len2; ++j) {
        p[0][j] = j;
    }
    //进行dp
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                p[i][j] = p[i - 1][j] + 1;
                if (p[i][j - 1] + 1 < p[i][j]) {
                    p[i][j] = p[i][j - 1] + 1;
                }
                if (p[i][j] > p[i - 1][j - 1]) {
                    p[i][j] = p[i - 1][j - 1];
                }
            } else {
                p[i][j] = p[i - 1][j];
                if (p[i][j] > p[i][j - 1]) {
                    p[i][j] = p[i][j - 1];
                }
                if (p[i][j] > p[i - 1][j - 1]) {
                    p[i][j] = p[i - 1][j - 1];
                }
                p[i][j] += 1;
            }
        }
    }
    return p[len1][len2];
}


/**
 * 思想不变只不过使用二维数组有点浪费，可以优化成一维数组
 * 这是一位我们只能用到相邻的数据，不会用到其他位置的数据
 * x x
 * x o ->
 *
 * xt xt-1 -> xt 0t
 * 要把xt-1 保存在 x0中
 * @param word1
 * @param word2
 * @return
 */
int minDistance2(string word1, string word2) {
    if (word1.size() == 0||word2.size()==0) {
        return word2.size()+word1.size();
    }
    int len2 = word2.size();
    int *p = new int[len2 + 1];
    //初始化
    for (int i = 0; i < len2 + 1; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < word1.size(); ++i) {
        //存放上一个状态
        p[0] = i;
        for (int j = 1; j < len2 + 1; ++j) {
            int min = p[0];
            if (word1[i] != word2[j - 1]) {
                min = p[0] + 1;
            }
            p[0] = p[j];
            if (min > p[j] + 1) {
                min = p[j] + 1;
            }
            if (min > p[j - 1] + 1) {
                min = p[j - 1] + 1;
            }
            p[j] = min;
        }
    }
    return p[len2];
}
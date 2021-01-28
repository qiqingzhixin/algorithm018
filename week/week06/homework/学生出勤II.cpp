//
// Created by Administrator on 2020/12/05.
//

/**
 * 551.学生出勤记录I
 * 'A' : Absent，缺勤
 * 'L' : Late，迟到
 * 'P' : Present，到场
 * @param s
 * @return
 */
bool checkRecord(string s) {
    int aNum = 0, lNum = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='A'){
            aNum++;
            if (aNum > 1) {
                return false;
            }
        }
        if(s[i]=='L'){
            lNum++;
            if(lNum>2){
                return false;
            }
        }else{
            lNum=0;
        }
    }
    return true;
}

/**
 * 552.学生出勤记录II
 * 分析映射关系
 *
 *
 * @param n
 * @return
 */
int checkRecord(int n) {
    int M = 1000000007;
    long **p = new long *[3];
    for (int i = 0; i < 3; ++i) {
        p[i] = new long[2]{0};
    }
    p[0][0] = 1;
    p[1][0] = 1;
    p[0][1] = 1;
    for (int j = 1; j < n; ++j) {
        //p[0][0]
        long temp1 = (p[0][0] + p[1][0] + p[2][0]) % M;
        //p[0][1]
        long temp2 = (p[0][1] + p[1][1] + p[2][1] + p[1][0] + p[2][0]+p[0][0]) % M;
        p[2][1] = p[1][1];
        p[1][1] = p[0][1];
        p[2][0] = p[1][0];
        p[1][0] = p[0][0];
        p[0][0] = temp1;
        p[0][1] = temp2;
    }
    long sum = 0;
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 2; ++i) {
            sum = (sum + p[k][i]) % M;
        }
    }
    return (int)sum;
}
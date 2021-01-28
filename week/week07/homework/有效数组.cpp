//
// Created by Administrator on 2020/12/08.
//

/**
 * 使用数组
 * @param board
 * @return
 */
bool isValidSudoku3(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
        int hen[9]{0};
        int lie[9]{0};
        int zh[9]{0};
        for (int j = 0; j < 9; ++j) {
            //横
            if (board[i][j] != '.') {
                if (hen[board[i][j] - '1'] != 0) {
                    return false;
                } else {
                    hen[board[i][j] - '1']++;
                }
            }
            //竖
            if (board[j][i] != '.') {
                if (lie[board[j][i] - '1'] != 0) {
                    return false;
                } else {
                    lie[board[j][i] - '1']++;
                }
            }
            //正方形
            int tempI = (i / 3) * 3 + j / 3;
            int tempJ = (i % 3) * 3 + j % 3;
            if (board[tempI][tempJ] != '.') {
                if (zh[board[tempI][tempJ] - '1'] != 0) {
                    return false;
                } else {
                    zh[board[tempI][tempJ] - '1']++;
                }
            }
        }
    }
    return true;
}
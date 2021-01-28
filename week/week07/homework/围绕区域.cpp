//
// Created by Administrator on 2020/12/08.
//

void solve(vector<vector<char>> &board) {
    int n = board.size();
    if (n == 0) {
        return;
    }
    int m = board[0].size();
    if (m == 0) {
        return;
    }
    int dis[4][2] = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };
    //将四周的变成Q
    for (int i = 0; i < n; ++i) {
        if (board[i][0] == 'O') {
            vistedSolve(board, dis, 'O', 'Q', i, 0);
        }
        if (board[i][m - 1] == 'O') {
            vistedSolve(board, dis, 'O', 'Q', i, m - 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (board[0][i] == 'O') {
            vistedSolve(board, dis, 'O', 'Q', 0, i);
        }
        if (board[n - 1][i] == 'O') {
            vistedSolve(board, dis, 'O', 'Q', n - 1, i);
        }
    }
    // 将中间的O改成X
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (board[i][j] == 'O') {
                vistedSolve(board, dis, 'O', 'X', i, j);
            }
        }
    }

    //将Q变回O
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'Q') {
                vistedSolve(board, dis, 'Q', 'O', i, j);
            }
        }
    }
}

/**
 *
 * @param board
 * @param p 方向
 * @param vistedchar 要拜访的字符
 * @param changechar 改成的字符
 * @param i
 * @param j
 */
void vistedSolve(vector<vector<char>> &board, int p[4][2], char vistedchar, char changechar, int i, int j) {
    board[i][j] = changechar;
    int tempi;
    int tempj;
    for (int k = 0; k < 4; ++k) {
        tempi = i + p[k][0];
        tempj = j + p[k][1];
        if (tempi >= 0 && tempi < board.size() && tempj >= 0 && tempj < board[0].size() && board[tempi][tempj] == vistedchar) {
            vistedSolve(board, p, vistedchar, changechar, tempi, tempj);
        }
    }
}
//
// Created by Administrator on 2020/11/15.
//

vector<vector<int>> direction529 = {
        {1,  0},
        {-1, 0},
        {1,  1},
        {-1, 1},
        {1,  -1},
        {-1, -1},
        {0,  -1},
        {0,  1},
};

/**
 * 第一种方案 是在本函数递归 ， 多次创建容器，造成耗时比较严重，虽然也能通过但是几百率在百分之5左右，
 * @param board
 * @param click
 * @return
 */
vector<vector<char>> updateBoard1(vector<vector<char>> &board, vector<int> &click) {
    char deal = board[click[0]][click[1]];
    //挖到雷了
    if (deal == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    if (deal == 'E') {
        int num = landmineNum(board, click[0], click[1]);
        if (num == 0) {
            board[click[0]][click[1]] = 'B';
            for (int i = 0; i < direction529.size(); ++i) {
                int tempI = click[0] + direction529[i][0];
                int tempJ = click[1] + direction529[i][1];
                if (tempI >= 0 && tempI < board.size() && tempJ >= 0 && tempJ < board[tempI].size()) {
                    //创建容器比较耗时
                    vector<int> temp = {tempI, tempJ};
                    updateBoard1(board, temp);
                }
            }
        } else {
            board[click[0]][click[1]] = ('0' + num);
        }

    }
    return board;
}

/**
 * 改进办，就是不用本函数递归，创建一个新的函数进行递归，这样的速度击败了98的用户。
 */
vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
    if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    if (board[click[0]][click[1]] == 'E') {
        updateBoardDfs(board, click[0], click[1]);
    }
    return board;
}

void updateBoardDfs(vector<vector<char>> &board, int i, int j) {
    int num = landmineNum(board, i, j);
    if (num == 0) {
        board[i][j] = 'B';
        for (int k = 0; k < direction529.size(); ++k) {
            int tempI = i + direction529[k][0];
            int tempJ = j + direction529[k][1];
            if (tempI >= 0 && tempI < board.size() && tempJ >= 0 && tempJ < board[tempI].size() &&
                board[tempI][tempJ] == 'E') {
                updateBoardDfs(board, tempI, tempJ);
            }
        }
    } else {
        board[i][j] = '0' + num;
    }
}

/**
 * 多少雷
 * @param board
 * @param i
 * @param j
 * @return
 */
int landmineNum(vector<vector<char>> &board, int i, int j) {
    int index = 0;
    for (int k = 0; k < direction529.size(); ++k) {
        int tempI = i + direction529[k][0];
        int tempJ = j + direction529[k][1];
        if (tempI >= 0 && tempI < board.size() && tempJ >= 0 && tempJ < board[tempI].size() &&
            board[tempI][tempJ] == 'M') {
            index++;
        }
    }
    return index;
}
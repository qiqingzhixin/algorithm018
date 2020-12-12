//
// Created by Administrator on 2020/12/07.
//

/**
 * 深度优先遍历
 * @param M
 * @return
 */
int findCircleNum(vector <vector<int>> &M) {
    int count = 0;
    int n = M.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (M[i][j] == 1) {
                count++;
                M[i][j] = 0;
                visted(M, j);
            }
        }
    }
    return count;
}

void visted(vector <vector<int>> &M, int i) {
    for (int j = 0; j < M.size(); ++j) {
        if (M[i][j] == 1) {
            M[i][j] = 0;
            visted(M, j);
        }
    }
}

/**
 * 547.朋友圈
 * 并查集的方式
 * 超时
 * @param M
 * @return
 */
int findCircleNum(vector <vector<int>> &M) {
    int n = M.size();
    int *p = new int[n];
    for (int k = 0; k < n; ++k) {
        p[k] = k;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (M[i][j] == 1) {
                unionParent(p, i, j);
                for (int i = 0; i < n; ++i) {
                    cout << p[i] << '\t';
                }
                cout << endl;
            }
        }
    }
    int count = 0;
    for (int l = 0; l < n; ++l) {
        if (p[l] == l) {
            count++;
        }
    }
    return count;
}

/**
 * 找爸爸
 * @param p
 * @param length
 * @param index
 * @return
 */
int findParent(int *p, int index) {
    while (p[index] != index) {
        index = p[index];
    }
    return index;
}

void unionParent(int *p, int indexA, int indexB) {
    int aParent = findParent(p, indexA);
    int bParent = findParent(p, indexB);
    if (aParent != bParent) {
        p[bParent] = aParent;
    }
}
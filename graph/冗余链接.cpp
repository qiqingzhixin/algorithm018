//
// Created by Administrator on 2021/01/27.
//

/**
 * 荣誉链接
 * @param edges
 * @return
 */
vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int len = edges.size() + 1;
    int *p = new int[len * 2];
    for (int i = 0; i < len * 2; i++) {
        p[i] = i;
    }
    for (int j = 0; j < edges.size(); ++j) {
        cout << endl;
        int r1 = findRedundantConnectionFind(p, edges[j][0]);
        int r2 = findRedundantConnectionFind(p, edges[j][1]);
        if (r1 == r2) {
            return edges[j];
        }
        findRedundantConnectionMerge(p, r1, r2);
    }
    return {};
}

int findRedundantConnectionFind(int *p, int i) {
    while (p[i] != i) {
        //缩短搜索路径
        p[i] = p[p[i]];
        i = p[i];
    }
    return i;
}
void findRedundantConnectionMerge(int *p, int i, int j) {
    p[i] = j;
}
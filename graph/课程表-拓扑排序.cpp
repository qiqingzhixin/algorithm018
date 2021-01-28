//
// Created by Administrator on 2021/01/27.
//



/**
 * 207 课程表
 * @param numCourses
 * @param prerequisites
 * @return
 */
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    int *p = new int[numCourses]{0};
    int result = 0;
    //
    unordered_map<int, vector<int>> map;
    for (vector<int> item : prerequisites) {
        //统计入度
        p[item[0]]++;
        if (map.count(item[1]) == 0) {
            //记录对应的入度
            map[item[1]] = {item[0]};
        } else {
            map[item[1]].push_back(item[0]);
        }
    }
    queue<int> queue;
    for (int i = 0; i < numCourses; ++i) {
        if (p[i] == 0) {
            queue.push(i);
        }
    }
    while (queue.size() > 0) {
        //        for (int i = 0; i < numCourses; ++i) {
        //            cout << p[i] << '\t';
        //        }
        //        cout << endl;
        int item = queue.front();
        queue.pop();
        result++;
        if (map.count(item) > 0) {
            vector<int> children = map[item];
            for (int index : children) {
                //减小入度
                p[index]--;
                if (p[index] == 0) {
                    queue.push(index);
                }
            }
        }
    }
    return result == numCourses;
}
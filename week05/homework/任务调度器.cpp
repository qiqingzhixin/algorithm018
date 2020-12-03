//
// Created by Administrator on 2020/11/30.
//

/**
     * 采用优先队列
     * @param tasks
     * @param n
     * @return
     */
int leastInterval(vector<char> &tasks, int n) {
    int *taskMap = new int[26]{0};
    int time = 0;
    for (int i = 0; i < tasks.size(); ++i) {
        taskMap[tasks[i] - 'A']++;
    }
    priority_queue<int> queue;
    for (int i = 0; i < 26; ++i) {
        if (taskMap[i] > 0) {
            queue.push(taskMap[i]);
        }
    }
    while (!queue.empty()) {
        //存暂时使用过的数组
        vector<int> temp;
        for (int i = 0; i <= n; ++i) {
            if (queue.top() > 1) {
                temp.push_back(queue.top() - 1);
            }
            queue.pop();
            //记录使劲啊
            time++;
            if (queue.empty()) {
                //队列中没有任务
                if (temp.size() != 0) {
                    //之前有处理过任务
                    time += (n - i);
                }
                break;
            }
        }
        //将之前的任务放到队列中继续处理
        for (int j = 0; j < temp.size(); ++j) {
            queue.push(temp[j]);
        }
    }
    return time;
}


/**
 * 具体步骤就是
 *
 * 1.先找到一个任务最多的（A)
 * 2.再找和A任务一个一样多的任务数(cnt)
 * 3.剩下的任务一定小于A任务，这时候我们就可以
 * 4.如果A任务下能容下的任务数是 (cnt+1)+(num(A)-1)*(n+1)
 * 5.总的任务数 tasks.size()=tasksNum;
 * 6.谁大取谁
 * A B C X | X
 * A B X X | X
 * ... X X | X
 * A B
 * @param tasks
 * @param n
 * @return
 */
int leastInterval2(vector<char> &tasks, int n) {
    int *p = new int[26]{0};
    for (int i = 0; i < tasks.size(); ++i) {
        p[tasks[i] - 'A']++;
    }
    //排序
    sort(p, p + 26, [](int &x, int &y) { return x > y; });
    int index = 1;
    while (index < 26 && p[0] == p[index]) {
        index++;
    }
    int m1 = index + (p[0] - 1) * (n + 1);
    return m1 > tasks.size() ? m1 : tasks.size();
}
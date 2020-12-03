//
// Created by Administrator on 2020/12/03.
//


/**
 * 403 青蛙过河 DFS 超时
 * p[i][j]=k 第i个石子第j种跳发
 * [0,1,3,5,6,8,12,17]
 * @param stones
 * @return
 */
bool canCross(vector<int> &stones) {
    return canCrossHelp(stones, 0, 1);
}

/**
 * 在 第index位置跳k步
 * @param stones
 * @param index 在那个坐标
 * @param k 要跳多少步
 * @return
 */
bool canCrossHelp(vector<int> &stones, int index, int k) {
    if (k <= 0) {
        return false;
    }
    // 跳到下一个数字
    int next = stones[index] + k;
    if (next == stones[stones.size() - 1]) {
        //跳到了终点
        return true;
    } else if (next > stones[stones.size() - 1]) {
        //跳过了
        return false;
    }
    //最左边
    int left = index + 1;
    int right = stones.size() - 1;
    int mid;
    bool flag = false;
    //二分查找
    while (left <= right) {
        mid = (left + right) / 2;
        if (stones[mid] == next) {
            //找到了
            flag = canCrossHelp(stones, mid, k - 1) || canCrossHelp(stones, mid, k) ||
                   canCrossHelp(stones, mid, k + 1);
            //有真的
            if (flag) {
                return flag;
            } else {
                break;
            }
        } else if (stones[mid] > next) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    //没有真的
    return false;
}


/**
 * 采用记忆集的方式
 * vector<int> *p=new vector<int>[size]
 * p[i] 记录跳到i可以跳的步数
 *
 * map + set 的用法
 * @param stones
 * @return
 */
bool canCross2(vector<int> &stones) {
    auto p = new unordered_set<int>[stones.size()];
    //方便快速定位坐标
    unordered_map<int, int> stones_map;
    for (int j = 0; j < stones.size(); ++j) {
        stones_map[stones[j]] = j;
    }
    p[0].insert(1);
    for (int i = 0; i < stones.size(); ++i) {
        for (int x:p[i]) {
            //跳到第几个单元
            int next = stones[i] + x;
            if (next == stones[stones.size() - 1]) {
                return true;
            }
            if (stones_map.count(next) > 0) {
                //找到了
                int nextIndex = stones_map[next];
                if (x - 1 > 0) {
                    p[nextIndex].insert(x - 1);
                }
                p[nextIndex].insert(x);
                p[nextIndex].insert(x + 1);
            }
        }
    }
    return false;
}
//
// Created by Administrator on 2020/11/08.
//

vector <vector<int>> permuteUnique(vector<int> &nums) {
    vector <vector<int>> result;
    permuteUniqueHelp(result, nums, 0);
    return result;
}

/**
 *
 * 剪掉用过的数
 * @param result
 * @param nums
 * @param k
 */
void permuteUniqueHelp(vector <vector<int>> &result, vector<int> &nums, int k) {
    if (k == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    set<int> used;
    for (int i = k; i < nums.size(); ++i) {
        int temp = nums[i];
        if (used.find(temp) == used.end()) {
            used.insert(temp);
            nums[i] = nums[k];
            nums[k] = temp;
            permuteUniqueHelp(result, nums, k + 1);
            temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;
        }
    }
}


vector <vector<int>> permuteUnique2(vector<int> &nums) {
    vector <vector<int>> result;
    permuteUniqueHelp(result, nums, 0);
    return result;
}

/**
 *
 * 剪掉用过的数
 * 优化了访问参数的记录方法
 * @param result
 * @param nums
 * @param k
 */
void permuteUniqueHelp2(vector <vector<int>> &result, vector<int> &nums, int k) {
    if (k == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    int visited[21] = {0};
    for (int i = k; i < nums.size(); ++i) {
        int temp = nums[i];
        if (visited[nums[i] + 10] == 0) {
            visited[nums[i] + 10] = 1;
            nums[i] = nums[k];
            nums[k] = temp;
            permuteUniqueHelp(result, nums, k + 1);
            temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;
        }
    }
}
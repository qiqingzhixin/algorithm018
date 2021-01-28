//
// Created by Administrator on 2021/01/27.
//
vector<string> summaryRanges(vector<int> &nums) {
    vector<string> result;
    nums.push_back(nums[nums.size() - 1] + 2);
    int start = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[start] - nums[i] != start - i) {
            result.push_back(summaryRangesString(nums[start], nums[i - 1]));
            start = i;
        }
    }
    return result;
}
string summaryRangesString(int i, int j) {
    if (i == j) {
        return to_string(i);
    } else {
        return to_string(i) + "->" + to_string(j);
    }
}
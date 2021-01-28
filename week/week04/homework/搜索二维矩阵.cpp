//
// Created by Administrator on 2020/11/15.
//

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //矩阵为null 的情况
    if(matrix.size()==0||matrix[0].size()==0){
        return false;
    }
    int start = 0;
    int end = matrix.size() - 1;
    int min;
    while (start <= end) {
        min = (start + end) / 2;
        if (matrix[min][0] == target) {
            return true;
        }
        if (matrix[min][0] < target) {
            if (matrix[min][matrix[min].size() - 1] >= target) {
                break;
            } else {
                start = min + 1;
            }
        } else {
            end = min - 1;
        }
    }
    start = 0;
    end = matrix[min].size() - 1;
    int min2;
    while (start <= end) {
        min2 = (start + end) / 2;
        if (matrix[min][min2] == target) {
            return true;
        }
        if (matrix[min][min2] < target) {
            start = min2 + 1;
        } else {
            end = min2 - 1;
        }
    }
    return false;
}
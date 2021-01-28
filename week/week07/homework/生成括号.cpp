//
// Created by Administrator on 2020/12/08.
//

/**
* 22.生成括号
* @param n
* @return
*/
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string item="";
    generateParenthesisHelp(n, result, item, 0, 0);
    return result;
}

void generateParenthesisHelp(int n, vector<string> &result, string &item, int left, int right) {
    if (left > n || left < right) {
        return;
    }
    if (n == right) {
        result.push_back(item);
        return;
    }
    item.push_back('(');
    generateParenthesisHelp(n, result, item , left + 1, right);
    item.pop_back();
    item.push_back(')');
    generateParenthesisHelp(n, result, item , left, right + 1);
    item.pop_back();
}
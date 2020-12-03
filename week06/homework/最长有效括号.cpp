//
// Created by Administrator on 2020/12/02.
//

/**
 * 最长有效括号 动态规划
 * if p[i]==')' &&p[i-1]=='(' 则 p[i]=p[i-2]+2;
 * if p[i]==')' &&p[i-1]==')' && s[i-p[i-1]-1]=='(' 则 p[i]=p[i-1]+2+p[i-p[i-1]-2]
 *
 * @param s
 * @return
 */
int longestValidParentheses2(string s) {
    if (s.size() <= 1) {
        return 0;
    }
    //存放最大值
    int max = 0;
    int *p = new int[s.size()]{0};
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                p[i] = (i - 2 >= 0 ? p[i - 2] : 0) + 2;
            } else if (i - p[i - 1] - 1 >= 0 && s[i - 1] == ')' && s[i - p[i - 1] - 1] == '(') {
                p[i] = p[i - 1] + 2 + (i - p[i - 1] - 2 >= 0 ? p[i - p[i - 1] - 2] : 0);
            }
            max = p[i] > max ? p[i] : max;
        }
    }
    return max;
}


/**
 * 使用栈的思想
 *
 * 所有的'('位置，如果遇到')'栈顶位置就是与之匹配的'('字符，就能计算出有效括号的长度
 * @param s
 * @return
 */

int longestValidParentheses3(string s) {
    int max = 0;
    stack<int> stack;
    //存放初始位置
    stack.push(-1);
    for (int i = 0; i < s.size(); ++i) {

        if (s[i] == '(') {
            stack.push(i);
        } else {
            stack.pop();
            if (stack.empty()) {
                stack.push(i);
            } else {
                int temp = i - stack.top();
                max = (temp > max ? temp : max);
            }
        }
    }
    return max;
}


/**
 * 计数左右括号的数量
 * 只要有左括号，来个右括号就能匹配
 * 当相等就有可能是最大的
 * 当右括号大于左括号则说明，新的一轮开始
 *
 * 为了防止左括号过多无法得到相等情况，反着再来一遍
 * @param s
 * @return
 */
int longestValidParentheses4(string s) {
    int max = 0, left = 0, right = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max = left * 2;
        } else if (left < right) {
            left = 0;
            right = 0;
        }
    }

    for (int j = s.size() - 1; j >= 0; --j) {
        if (s[j] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max = left * 2;
        } else if (right < left) {
            left = 0;
            right = 0;
        }
    }
    return max;
}
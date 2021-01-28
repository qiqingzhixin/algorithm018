//
// Created by Administrator on 2021/01/27.
//

class Solution {
private:
    int index;
    bool first;

    bool inOrderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        bool flag = inOrderTraversal(root->left);
        flag = flag && (first || index < root->val);
        first = false;
        index = root->val;
        flag = flag && inOrderTraversal(root->right);
        return flag;
    }

public:
    bool isValidBST(TreeNode *root) {
        first = true;
        return inOrderTraversal(root);
    }
};
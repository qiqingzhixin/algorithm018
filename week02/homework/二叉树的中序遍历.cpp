//
// Created by Administrator on 2020/10/31.
//

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    return inorderTraversalHelp(root, result);
}

vector<int> inorderTraversalHelp(TreeNode *root, vector<int> &result) {
    if (root == NULL) {
        return result;
    }
    inorderTraversalHelp(root->left, result);
    result.push_back(root->val);
    inorderTraversalHelp(root->right, result);
    return result;
}
//
// Created by Administrator on 2020/10/31.
//

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    return preorderTraversalHelp(root, result);
}

vector<int> preorderTraversalHelp(TreeNode *root, vector<int> &result) {
    if (root == NULL) {
        return result;
    }
    result.push_back(root->val);
    preorderTraversalHelp(root->left, result);
    preorderTraversalHelp(root->right, result);
    return result;
}
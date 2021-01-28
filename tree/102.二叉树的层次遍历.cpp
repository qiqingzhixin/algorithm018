//
// Created by Administrator on 2021/01/28.
//

vector<vector<int>> levelOrder(TreeNode *root) {
    if (root== nullptr){
        return {};
    }
    vector<vector<int>> result;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> item;
        for (int i = 0; i < size; ++i) {
            TreeNode *node = que.front();
            que.pop();
            item.push_back(node->val);
            if (node->left != nullptr) {
                que.push(node->left);
            }
            if (node->right != nullptr) {
                que.push(node->right);
            }
        }
        result.push_back(item);
    }
    return result;
}
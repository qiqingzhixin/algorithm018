//
// Created by Administrator on 2021/01/28.
//

TreeNode *addOneRow(TreeNode *root, int v, int d) {
    if(d==1){
        return new TreeNode(v,root,nullptr);
    }
    queue<TreeNode *> q;
    int count = 1;
    q.push(root);
    d--;
    for (; count < d; count++) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *item = q.front();
            q.pop();
            if (item->left != nullptr) {
                q.push(item->left);
            }
            if (item->right != nullptr) {
                q.push(item->right);
            }
        }
    }
    while (!q.empty()) {
        TreeNode *item = q.front();
        q.pop();

        item->left = new TreeNode(v, item->left, nullptr);

        item->right = new TreeNode(v, nullptr, item->right);
    }
    return root;
}
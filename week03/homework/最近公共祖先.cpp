//
// Created by Administrator on 2020/11/08.
//

/**
 *  定义函数返回两个节点的祖先
 *
 * @param root
 * @param p
 * @param q
 * @return
 */
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr && right == nullptr) {
        return nullptr;
    }
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    return root;
}
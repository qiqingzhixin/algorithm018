//
// Created by Administrator on 2021/01/27.
//
bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p== nullptr&&q== nullptr){
        return true;
    }
    if ((p== nullptr&&q!= nullptr)||(p!= nullptr&&q== nullptr)||( p->val != q->val)) {
        return false;
    }
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}
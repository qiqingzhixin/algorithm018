//
// Created by Administrator on 2020/11/08.
//

/**
 * 执行耗时:48 ms,击败了35.01% 的C++用户
 * 内存消耗:66.4 MB,击败了10.98% 的C++用户
 * @param preorder
 * @param inorder
 * @return
 */
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    //出口
    if (preorder.size() == 0 || inorder.size() == 0) {
        return nullptr;
    }
    int rootnum = preorder[0];
    //中序遍历根节点的位置
    int inIndex = 0;
    for (inIndex = 0; inIndex < inorder.size(); ++inIndex) {
        if (inorder[inIndex] == rootnum) {
            break;
        }
    }
    //根节点
    TreeNode *root;
    if (inIndex == 0 && inIndex == inorder.size() - 1) {
        //没有左子树
        root = new TreeNode(preorder[0], nullptr, nullptr);
    } else if (inIndex == 0) {
        // 没有左子树
        vector<int> childPreOrder(preorder.begin() + 1, preorder.end());
        vector<int> childInorder(inorder.begin() + 1, inorder.end());
        root = new TreeNode(preorder[0], nullptr, buildTree(childPreOrder, childInorder));
    } else if (inIndex == inorder.size() - 1) {
        //没有右子树
        vector<int> childPreOrder(preorder.begin() + 1, preorder.end());
        vector<int> childInOrder(inorder.begin(), inorder.end() - 1);
        root = new TreeNode(preorder[0], buildTree(childPreOrder, childInOrder), nullptr);
    } else {
        //左子树中序遍历
        vector<int> leftInOrder(inorder.begin(), inorder.begin() + inIndex);
        //左子树前序遍历
        vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + (leftInOrder.size() + 1));
        //右子树前序遍历
        vector<int> rightPreOrder(preorder.begin() + (leftInOrder.size() + 1), preorder.end());
        //右子树中序遍历
        vector<int> rightInOrder(inorder.begin() + (inIndex + 1), inorder.end());
        root = new TreeNode(preorder[0], buildTree(leftPreOrder, leftInOrder), buildTree(rightPreOrder, rightInOrder));
    }
    return root;
}

/**
 * 第二种解法
 *执行耗时:44 ms,击败了41.31% 的C++用户
 *内存消耗:17.5 MB,击败了36.41% 的C++用户
 * @param preorder
 * @param inorder
 * @return
 */
TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder) {
    return buildTreeHelp(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode *
buildTreeHelp(vector<int> &preorder, vector<int> &inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
    TreeNode *root;
    if (preBegin > preEnd) {
        return nullptr;
    } else {
        //在中序遍历中的坐标
        int rootIndex;
        for (rootIndex = inBegin; rootIndex <= preEnd; rootIndex++) {
            if (inorder[rootIndex] == preorder[preBegin]) {
                break;
            }
        }
        root = new TreeNode(preorder[preBegin],
                            buildTreeHelp(preorder, inorder, preBegin + 1, preBegin + (rootIndex-inBegin), inBegin,
                                          rootIndex - 1),
                            buildTreeHelp(preorder, inorder, preBegin+(rootIndex-inBegin + 1), preEnd, rootIndex + 1,
                                          inEnd));
    }
    return root;
}
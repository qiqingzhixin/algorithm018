//
// Created by Administrator on 2020/10/31.
//

vector<int> preorder(Node *root) {
    vector<int> result;
    return preorderhelp(root, result);
}

vector<int> preorderhelp(Node *root, vector<int> &result) {
    if (root == NULL) {
        return result;
    }
    result.push_back(root->val);
    vector < Node * > children = root->children;
    for (int i = 0; i < children.size(); ++i) {
        preorderhelp(children[i], result);
    }
    return result;
}
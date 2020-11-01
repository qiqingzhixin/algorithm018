//
// Created by Administrator on 2020/10/31.
//

vector <vector<int>> levelOrder(Node *root) {
    if (root == NULL) {
        return {};
    }
    queue < Node * > current;
    current.push(root);
    vector <vector<int>> result;
    while (current.size() > 0) {
        queue < Node * > next;
        vector<int> items;
        while (!current.empty()) {
            //处理第一个
            items.push_back(current.front()->val);
            vector < Node * > children = current.front()->children;
            for (int i = 0; i < children.size(); ++i) {
                if (children[i] != NULL) {
                    next.push(children[i]);
                }
            }
            //删除第一个
            current.pop();
        }
        result.push_back(items);
        current = next;
    }
    return result;
}
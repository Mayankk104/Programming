#include <bits/stdc++.h>

#include "../lib/headers/tree.hpp"
#include "../lib/headers/views.hpp"

using namespace std;

vector<int> TreeViews::right_view(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> result;
    TreeNode* prev = root;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        if (front == NULL) {
            result.push_back(prev->val);
            if (q.size() > 0) q.push(NULL);
        } else {
            if (front->left != NULL) q.push(front->left);
            if (front->right != NULL) q.push(front->right);
        }
        if (front != NULL) prev = front;
    }

    cout << "Right View Of Tree: ";
    for (auto node : result) cout << node << " ";
    cout << endl;

    return result;
}
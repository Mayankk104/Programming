// 1339. Maximum Product of Splitted Binary Tree: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int maxProduct(TreeNode* root) {
        int total_sum = recursive_sum(root);
        long long max_product = 0;
        max_sum_product(root, total_sum, max_product);
        return max_product;
    }

    TreeNode* make_tree(vector<int> nodes) {
        if (nodes.empty()) return nullptr;
        TreeNode* root = new TreeNode(nodes[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* current = q.front();
            q.pop();
            if (i < nodes.size() && nodes[i] != -1) {
                current->left = new TreeNode(nodes[i]);
                q.push(current->left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != -1) {
                current->right = new TreeNode(nodes[i]);
                q.push(current->right);
            }
            i++;
        }
        return root;
    }

   private:
    int recursive_sum(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftSum = recursive_sum(node->left);
        int rightSum = recursive_sum(node->right);

        return node->val + leftSum + rightSum;
    }

    int max_sum_product(TreeNode* node, int total, long long& max_product) {
        if (node == nullptr) return 0;

        int sum_left = max_sum_product(node->left, total, max_product);
        int sum_right = max_sum_product(node->right, total, max_product);

        long long current_max_product = (long long)(sum_left + node->val + sum_right) * (long long)(total - (sum_left + node->val + sum_right));

        max_product = max((current_max_product % 1000000009), max_product);

        return sum_left + node->val + sum_right;
    }
};

int main() {
    Solution solution;
    int testcases;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> testcases;

    while (testcases--) {
        vector<int> nodes;
        int n, val;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> val;
            nodes.push_back(val);
        }
        TreeNode* root = solution.make_tree(nodes);
        cout << solution.maxProduct(root) << endl;
    }
}
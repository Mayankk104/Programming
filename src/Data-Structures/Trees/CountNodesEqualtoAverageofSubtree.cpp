// 2265. Count Nodes Equal to Average of Subtree https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/ #WeeklyContest 292
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    pair<int, int> helper(TreeNode *node, int &count) {
        pair<int, int> p = {node->val, 1};

        if (node->right != NULL) {
            pair<int, int> tempP = helper(node->right, count);
            p.first += tempP.first;
            p.second += tempP.second;
        }

        if (node->left != NULL) {
            auto tempP = helper(node->left, count);
            p.first += tempP.first;
            p.second += tempP.second;
        }

        if (node->val == (p.first / p.second))
            count++;

        return p;
    }

    int averageOfSubtree(TreeNode *root) {
        int count = 0;
        helper(root, count);
        return count;
    }
};

int main() {
    Solution s;

    TreeNode n(4);
    TreeNode n2(10);
    TreeNode n3(100);
    TreeNode *ptr = &n;

    n.left = &n2;
    n.right = &n3;

    cout << s.averageOfSubtree(ptr);
}
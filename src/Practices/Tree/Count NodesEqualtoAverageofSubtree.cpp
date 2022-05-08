// 2265. Count Nodes Equal to Average of Subtree https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/ #WeeklyContest 292
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int count;

    pair<int, int> helper(TreeNode *node)
    {
        pair<int, int> p = {node->val, 1};

        if (node->right != NULL)
        {
            pair<int, int> tempP = helper(node->right);
            p.first += tempP.first;
            p.second += tempP.second;
        }

        if (node->left != NULL)
        {
            pair tempP = helper(node->left);
            p.first += tempP.first;
            p.second += tempP.second;
        }

        if (node->val == (p.first / p.second))
            this->count++;

        return p;
    }

    int averageOfSubtree(TreeNode *root)
    {
        helper(root);
        return count;
    }
};
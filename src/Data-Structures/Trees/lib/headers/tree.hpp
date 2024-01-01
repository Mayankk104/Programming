#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Tree {
   public:
    TreeNode* build_from_preorder_inorder(vector<int>& preorder, vector<int>& inorder);
    TreeNode* dummy_tree();
};
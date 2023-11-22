#pragma once

#include "./tree.hpp"

class TreeViews {
   public:
    vector<int> right_view(TreeNode* root);
    vector<int> left_view(TreeNode* root);
    vector<int> top_view(TreeNode* root);
    vector<int> bottom_view(TreeNode* root);
};

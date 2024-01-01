#include "./../headers/tree.hpp"

#include <vector>

using namespace std;

TreeNode* Tree::build_from_preorder_inorder(vector<int>& preorder, vector<int>& postorder) {
    // TODO: impliment
    return nullptr;
}

TreeNode* Tree::dummy_tree() {
    // TODO: remove
    TreeNode* n8 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(29);
    TreeNode* n5 = new TreeNode(28);
    TreeNode* n4 = new TreeNode(28, n8, NULL);
    TreeNode* n3 = new TreeNode(15, n6, n7);
    TreeNode* n2 = new TreeNode(10, n4, n5);
    TreeNode* n1 = new TreeNode(29, n2, n3);

    return n1;
}
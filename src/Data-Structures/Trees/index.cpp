#include "./lib/headers/tree.hpp"
#include "./lib/headers/views.hpp"

int main() {
    // ###### Declartions ######
    Tree tree;
    TreeNode* root = tree.dummy_tree();

    TreeViews views;

    // ==== Tree Views ====
    views.right_view(root);
}
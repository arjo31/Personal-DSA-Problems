/*Given the root of a binary tree, invert the tree, and return its root.*/

#include "binary_tree.h"

void solve(TreeNode *root)
{
    if (root == nullptr)
        return;
    if (root->left != nullptr)
        solve(root->left);
    if (root->right != nullptr)
        solve(root->right);

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
TreeNode *invertTree(TreeNode *root)
{
    solve(root);
    return root;
}
/*Given the root of a binary tree, invert the tree, and return its root.*/

#include "binary_tree.h"

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return root;

    invertTree(root->left);
    invertTree(root->right);
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}
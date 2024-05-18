/*Given a binary tree, determine if it is height-balanced.*/

#include "binary_tree.h"

int maxHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);

    if (rightHeight == -1 || leftHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return 1 + fmax(leftHeight, rightHeight);
}

bool isBalanced(TreeNode *root)
{
    return maxHeight(root) != -1;
}
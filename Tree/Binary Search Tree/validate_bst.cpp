/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

1. The left subtree of a node contains only nodes with keys less than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.
3. Both the left and right subtrees must also be binary search trees.*/

#include "binary_search_tree.h"

bool isValidBST(TreeNode *root, long minVal, long maxVal)
{
    if (root == nullptr)
        return true;
    if (root->val >= maxVal || root->val <= minVal)
        return false;
    return (isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal));
}
bool isBST(TreeNode *root)
{
    return isValidBST(root, LONG_MIN, LONG_MAX);
}
/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”*/

#include "binary_tree.h"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || root == p || root == q)
    {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == nullptr)
        return right;
    else if (right == nullptr)
        return left;
    else
        return root;
}

int lowestCommonAncestor(TreeNode *root, int x, int y) // LCA of two numbers
{
    if (root == nullptr)
        return -1;
    if (root->val == x || root->val == y)
        return root->val;

    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);

    if (left == -1)
        return right;
    else if (right == -1)
        return left;
    else
        return root->val;
}
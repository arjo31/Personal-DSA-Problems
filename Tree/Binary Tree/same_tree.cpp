/*Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.*/

#include "binary_tree.h"

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;
    return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
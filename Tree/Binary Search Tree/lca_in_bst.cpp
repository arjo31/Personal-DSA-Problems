/*Given a binary search tree (BST) where all node values are unique, and two nodes from the tree p and q, return the lowest common ancestor (LCA) of the two nodes.

The lowest common ancestor between two nodes p and q is the lowest node in a tree T such that both p and q as descendants. The ancestor is allowed to be a descendant of itself.*/

#include "binary_search_tree.h"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (true)
    {
        if (root->val < p->val && root->val < q->val)
            root = root->right;
        else if (root->val > p->val && root->val > q->val)
            root = root->left;
        else
            return root;
    }
}

// Recursive
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return root;
    int curr = root->val;
    if (curr < p->val && curr < q->val)
        return lowestCommonAncestor(root->right, p, q);
    if (curr > p->val && curr > q->val)
        return lowestCommonAncestor(root->left, p, q);
    return root;
}
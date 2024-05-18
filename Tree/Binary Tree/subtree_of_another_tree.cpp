/*Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.*/

#include "binary_tree.h"

// Recursive
bool solve(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr && subRoot == nullptr)
        return true;
    if (root == nullptr || subRoot == nullptr)
        return false;
    if (root->val != subRoot->val)
        return false;
    return solve(root->left, subRoot->left) && solve(root->right, subRoot->right);
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr)
        return false;
    if (subRoot == nullptr)
        return true;
    if (solve(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// Iterative
bool solve(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr && subRoot == nullptr)
        return true;
    if (root == nullptr || subRoot == nullptr)
        return false;
    if (root->val != subRoot->val)
        return false;
    return solve(root->left, subRoot->left) && solve(root->right, subRoot->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr || subRoot == nullptr)
    {
        return false;
    }
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        auto curr = nodes.front();
        nodes.pop();
        if (curr->left != nullptr)
        {
            nodes.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            nodes.push(curr->right);
        }

        if (curr->val == subRoot->val)
        {
            if (solve(curr, subRoot))
            {
                return true;
            }
        }
    }
    return false;
}
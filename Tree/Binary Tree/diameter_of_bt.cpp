/*Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.*/

#include "binary_tree.h"

int solve(TreeNode *root, int &res)
{
    if (root == nullptr)
        return 0;

    int left = solve(root->left, res);
    int right = solve(root->right, res);

    int temp = 1 + max(left, right);
    int ans = max(temp, 1 + left + right);
    res = max(res, ans);
    return temp;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}
/*Given a Binary Tree, find the maximum sum path from a leaf to root.*/

#include "binary_tree.h"

bool isLeaf(TreeNode *root)
{
    return (root->left == nullptr && root->right == nullptr);
}

int solve(TreeNode *root, int &res)
{
    if (root == nullptr)
        return INT_MIN;
    if (isLeaf(root))
        return root->val;

    int left = solve(root->left, res);
    int right = solve(root->right, res);

    int temp = max(left, right) + root->val;
    res = max(res, temp);
    return temp;
}

int maxPathSum(TreeNode *root)
{
    if (isLeaf(root))
        return root->val;
    int res = INT_MIN;
    solve(root, res);
    return res;
}
/*Given a binary tree in which each TreeNOde element contains a number. Find the maximum possible sum from one leaf TreeNOde to another.

The maximum sum path may or may not go through the root*/

#include "binary_tree.h"

int findMaxPathSum(TreeNode *root, int &res)
{
    if (root == NULL)
        return 0;

    int lsum = findMaxPathSum(root->left, res);
    int rsum = findMaxPathSum(root->right, res);

    if (!root->left and !root->right)
        return root->val;

    if (!root->left)
        return root->val + rsum;

    if (!root->right)
        return root->val + lsum;

    int temp = root->val + max(lsum, rsum);
    int ans = root->val + lsum + rsum;
    res = max(res, ans);
    return temp;
}

int maxPathSum(TreeNode *root)
{
    int res = INT_MIN;
    int ans = findMaxPathSum(root, res);
    if (!root->left or !root->right)
        res = max(res, ans);
    return res;
}
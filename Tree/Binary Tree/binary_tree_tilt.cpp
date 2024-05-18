/*Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.*/

#include "binary_tree.h"

int sum(TreeNode *root, int &ans)
{
    if (root == nullptr)
        return 0;
    int leftSum = sum(root->left, ans);
    int rightSum = sum(root->right, ans);
    ans += abs(leftSum - rightSum);
    return root->val + leftSum + rightSum;
}

int findTilt(TreeNode *root)
{
    int ans = 0;
    sum(root, ans);
    return ans;
}
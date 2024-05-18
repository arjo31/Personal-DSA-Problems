/*Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.*/

#include "binary_tree.h"

void leftLeavesSum(TreeNode *root, bool isLeft, int &sum)
{
    if (!root)
        return;

    if (!root->left && !root->right && isLeft)
        sum += root->val;

    leftLeavesSum(root->left, 1, sum);
    leftLeavesSum(root->right, 0, sum);
}
int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    leftLeavesSum(root, 0, sum);
    return sum;
}
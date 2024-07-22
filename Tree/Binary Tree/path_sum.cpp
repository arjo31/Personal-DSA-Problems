/*Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.*/

#include "binary_tree.h"
using namespace std;

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;

    targetSum = targetSum - root->val;

    if (targetSum == 0 && !root->left && !root->right)
        return true;

    bool left = hasPathSum(root->left, targetSum);
    bool right = hasPathSum(root->right, targetSum);

    return (left || right);
}
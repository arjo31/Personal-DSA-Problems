/*A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.*/

#include "binary_tree.h"

int maxPathDown(TreeNode *root, int &maxi)
{
    if (root == nullptr)
        return 0;
    int leftPath = fmax(0, maxPathDown(root->left, maxi));
    int rightPath = fmax(0, maxPathDown(root->right, maxi));
    maxi = fmax(maxi, root->val + leftPath + rightPath);
    return (root->val + max(leftPath, rightPath));
}

int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

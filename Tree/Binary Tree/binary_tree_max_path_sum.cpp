/*A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.*/

#include "binary_tree.h"

int solve(TreeNode *root, int &res)
{
    if (root == nullptr)
        return 0;

    int left = max(0, solve(root->left, res));
    int right = max(0, solve(root->right, res));

    int temp = max(left, right) + root->val;
    int ans = max(temp, root->val + left + right);
    res = max(ans, res);
    return temp;
}
int maxPathSum(TreeNode *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}

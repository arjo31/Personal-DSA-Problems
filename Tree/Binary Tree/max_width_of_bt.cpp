/*Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.*/

#include "binary_tree.h"

long long int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    long long int ans = 0;
    queue<pair<TreeNode *, long long int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        long long int size = q.size();
        long long int mmin = q.front().second;
        long long int first, last;
        for (long long int i = 0; i < size; i++)
        {
            long long int cur_id = q.front().second - mmin;
            TreeNode *node = q.front().first;
            q.pop();
            if (i == 0)
            {
                first = cur_id;
            }
            if (i == size - 1)
            {
                last = cur_id;
            }
            if (node->left)
            {
                q.push({node->left, cur_id * 2 + 1});
            }
            if (node->right)
            {
                q.push({node->right, cur_id * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}
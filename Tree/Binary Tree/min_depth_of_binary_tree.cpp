/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.*/

#include "binary_tree.h"

int minDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    queue<pair<int, TreeNode *>> q;
    q.push({1, root});
    while (!q.empty())
    {
        int count = q.front().first;
        TreeNode *newNode = q.front().second;
        q.pop();
        if (!newNode->left && !newNode->right)
            return count;
        if (newNode->left)
            q.push({count + 1, newNode->left});
        if (newNode->right)
            q.push({count + 1, newNode->right});
    }
    return -1;
}
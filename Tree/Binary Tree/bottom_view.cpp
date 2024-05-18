/*Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.*/

#include "binary_tree.h"

vector<int> bottomView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int line = it.second;
        mpp[line] = node->val;

        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
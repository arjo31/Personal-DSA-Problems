/*Given below is a binary tree.The task is to print the top view of binary tree.Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.*/

#include "binary_tree.h"

vector<int> topView(TreeNode *root)
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
        if (mpp.find(line) == mpp.end())
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
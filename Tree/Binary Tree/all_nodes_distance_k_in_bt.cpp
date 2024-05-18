/*Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.*/

#include "binary_tree.h"

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    queue<TreeNode *> q;
    vector<int> adj[501];
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            TreeNode *t = q.front();
            q.pop();
            if (t->left)
            {
                adj[t->val].push_back(t->left->val);
                adj[t->left->val].push_back(t->val);
                q.push(t->left);
            }
            if (t->right)
            {
                adj[t->val].push_back(t->right->val);
                adj[t->right->val].push_back(t->val);
                q.push(t->right);
            }
        }
    }
    queue<pair<int, int>> q1;
    q1.push({0, target->val});
    vector<int> vis(501, 0);
    vis[target->val] = 1;
    vector<int> ans;
    while (!q1.empty())
    {
        int steps = q1.front().first;
        int node = q1.front().second;
        q1.pop();

        if (steps == k)
        {
            ans.push_back(node);
            continue;
        }

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                q1.push({steps + 1, adjNode});
                vis[adjNode] = 1;
            }
        }
    }
    return ans;
}
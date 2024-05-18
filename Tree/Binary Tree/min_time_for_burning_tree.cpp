/*Given a binary tree and a node val called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.*/

#include "binary_tree.h"

int timeToBurnTree(TreeNode *root, int start)
{
    queue<TreeNode *> q;
    unordered_map<int, vector<int>> mpp;
    q.push(root);
    while (!q.empty()) // Convert binary tree to adjacency list
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            TreeNode *t = q.front();
            q.pop();

            if (t->left)
            {
                mpp[t->val].push_back(t->left->val);
                mpp[t->left->val].push_back(t->val);
                q.push(t->left);
            }

            if (t->right)
            {
                mpp[t->val].push_back(t->right->val);
                mpp[t->right->val].push_back(t->val);
                q.push(t->left);
            }
        }
    }
    queue<pair<int, int>> q1;
    q1.push({0, start});
    vector<int> vis(1e9, 0);
    vis[start] = 1;
    vector<int> ans;
    int mini = INT_MAX;
    while (!q1.empty())
    {
        int time = q1.front().first;
        int node = q1.front().second;
        q1.pop();
        mini = min(time, mini);

        for (auto adjNode : mpp[node])
        {
            if (!vis[adjNode])
            {
                q1.push({time + 1, adjNode});
                vis[adjNode] = 1;
            }
        }
    }
    return mini;
}

// Another Method
int maxDepth(TreeNode *n)
{
    if (!n)
        return 0;
    return 1 + max(maxDepth(n->left), maxDepth(n->right));
}

int traverse(TreeNode *n, int target, int &ret)
{
    if (!n)
        return 0;

    if (n->val == target)
    {
        ret = max(ret, maxDepth(n->right));
        ret = max(ret, maxDepth(n->left));
        return 1;
    }

    int val = traverse(n->left, target, ret);
    if (val)
    {
        ret = max(ret, val + maxDepth(n->right));
        return val + 1;
    }

    val = traverse(n->right, target, ret);
    if (val)
    {
        ret = max(ret, val + maxDepth(n->left));
        return val + 1;
    }

    return 0;
}

int minTime(TreeNode *root, int target)
{
    int ret = 0;
    traverse(root, target, ret);
    return ret;
}

// Another way
int findMaxDistance(map<TreeNode *, TreeNode *> &mpp, TreeNode *target)
{
    queue<TreeNode *> q;
    q.push(target);
    map<TreeNode *, int> vis;
    vis[target] = 1;
    int maxi = 0;
    while (!q.empty())
    {
        int sz = q.size();
        int fl = 0;
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left && !vis[node->left]) // left child
            {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !vis[node->right]) // right child
            {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }

            if (mpp[node] && !vis[mpp[node]]) // parent
            {
                fl = 2;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if (fl)
            maxi++;
    }
    return maxi;
}

TreeNode *bfsToMapParents(TreeNode *root, map<TreeNode *, TreeNode *> &mpp, int start)
{
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *res;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        if (node->val == start)
            res = node;
        q.pop();

        if (node->left)
        {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurnTree(TreeNode *root, int start)
{
    map<TreeNode *, TreeNode *> mpp;
    TreeNode *target = bfsToMapParents(root, mpp, start);
    int ans = findMaxDistance(mpp, target);
    return ans;
}
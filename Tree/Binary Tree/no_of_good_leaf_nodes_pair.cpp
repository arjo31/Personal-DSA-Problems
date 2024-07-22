/*You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.*/

#include "binary_tree.h"
using namespace std;

// Method 1: TLE

bool isLeaf(TreeNode *node)
{
    return (node->left == nullptr && node->right == nullptr);
}

int shortestDistance(TreeNode *src, TreeNode *dest, unordered_map<TreeNode *, vector<TreeNode *>> &adj)
{
    unordered_set<TreeNode *> vis;
    vis.insert(src);
    queue<pair<TreeNode *, int>> q;
    q.push({src, 0});
    while (!q.empty())
    {
        TreeNode *u = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (u == dest)
            return dist;

        for (TreeNode *v : adj[u])
        {
            if (!vis.count(v))
            {
                q.push({v, dist + 1});
                vis.insert(v);
            }
        }
    }
    return INT_MAX;
}

int countPairs(TreeNode *root, int distance)
{
    unordered_map<TreeNode *, vector<TreeNode *>> adj;
    if (root == nullptr)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    vector<TreeNode *> leafNodes;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *u = q.front();
            q.pop();
            if (u->left)
            {
                q.push(u->left);
                TreeNode *v = u->left;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            if (u->right)
            {
                q.push(u->right);
                TreeNode *v = u->right;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            if (isLeaf(u))
                leafNodes.push_back(u);
        }
    }
    int goodPairs = 0;
    int n = leafNodes.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dist = shortestDistance(leafNodes[i], leafNodes[j], adj);
            if (dist <= distance)
                goodPairs++;
        }
    }
    return goodPairs;
}

// A Bit Optimized Solution

unordered_set<TreeNode *> leafNodes;
int totalGoodPairs = 0;

bool isLeaf(TreeNode *node)
{
    return (node->left == nullptr && node->right == nullptr);
}

int shortestDistance(TreeNode *src, unordered_map<TreeNode *, vector<TreeNode *>> &adj, int distance)
{
    unordered_set<TreeNode *> vis;
    vis.insert(src);
    queue<pair<TreeNode *, int>> q;
    q.push({src, 0});
    while (!q.empty())
    {
        TreeNode *u = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (dist > distance)
            break;
        if (u != src && leafNodes.count(u))
            totalGoodPairs++;

        for (TreeNode *v : adj[u])
        {
            if (!vis.count(v))
            {
                q.push({v, dist + 1});
                vis.insert(v);
            }
        }
    }
    return INT_MAX;
}

int countPairs(TreeNode *root, int distance)
{
    unordered_map<TreeNode *, vector<TreeNode *>> adj;
    if (root == nullptr)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *u = q.front();
            q.pop();
            if (u->left)
            {
                q.push(u->left);
                TreeNode *v = u->left;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            if (u->right)
            {
                q.push(u->right);
                TreeNode *v = u->right;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            if (isLeaf(u))
                leafNodes.insert(u);
        }
    }
    int n = leafNodes.size();
    for (TreeNode *leaf : leafNodes)
    {
        shortestDistance(leaf, adj, distance);
    }
    return totalGoodPairs / 2;
}
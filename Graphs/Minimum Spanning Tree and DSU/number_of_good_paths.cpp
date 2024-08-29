/*There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return (parent[node] = findUParent(parent[node]));
    }

    void unionBySize(int u, int v)
    {
        u = findUParent(u);
        v = findUParent(v);
        if (u == v)
            return;
        if (size[u] > size[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
        else
        {
            parent[u] = v;
            size[v] += size[u];
        }
    }
};

int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
{
    int n = vals.size();
    vector<int> adj[n];
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DisjointSet ds(n);

    // val -> {nodes}
    map<int, vector<int>> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[vals[i]].push_back(i);
    }

    int ans = n;
    vector<bool> isActive(n, false);

    for (auto it : mpp)
    {
        vector<int> nodes = it.second;
        for (int u : nodes)
        {
            for (int v : adj[u])
            {
                if (isActive[v])
                    ds.unionBySize(u, v);
            }
            isActive[u] = true;
        }

        vector<int> ultimateParents;
        for (int u : nodes)
        {
            int parent = ds.findUParent(u);
            ultimateParents.push_back(parent);
        }
        sort(ultimateParents.begin(), ultimateParents.end());
        int sz = ultimateParents.size();
        for (int i = 0; i < sz; i++)
        {
            long long count = 0;
            int currParent = ultimateParents[i];

            while (i < sz && currParent == ultimateParents[i])
            {
                i++;
                count++;
            }
            i--;

            ans += (count * (count - 1) / 2);
        }
    }
    return ans;
}
/*There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[30001];
vector<int> subtreeSize(30001), dist(30001);

void dfs(int u = 0, int parent = -1)
{
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        dfs(v, u);
        subtreeSize[u] = subtreeSize[u] + subtreeSize[v];
        dist[u] = dist[u] + dist[v] + subtreeSize[v];
    }
}

void reroot(int n, int u = 0, int parent = -1)
{
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        dist[v] = dist[u] - subtreeSize[v] + (n - subtreeSize[v]);
        reroot(n, v, u);
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist.assign(n, 0);
    subtreeSize.assign(n, 1);
    dfs();
    reroot(n);
    return dist;
}
/*You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.*/

#include <bits/stdc++.h>
using namespace std;

int minScorePath = INT_MAX;

void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis)
{
    if (vis[node])
        return;
    vis[node] = 1;
    for (auto v : adj[node])
    {
        minScorePath = min(minScorePath, v.second);
        if (!vis[v.first])
        {
            dfs(v.first, adj, vis);
        }
    }
}

int minScore(int n, vector<vector<int>> &roads)
{
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < roads.size(); i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        int d = roads[i][2];
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    vector<int> vis(n + 1, 0);
    dfs(1, adj, vis);
    return minScorePath;
}
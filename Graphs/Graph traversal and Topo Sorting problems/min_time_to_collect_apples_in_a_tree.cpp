/*Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.*/

#include <bits/stdc++.h>
using namespace std;

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    vector<int> adj[n];
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return dfs(hasApple, 0, -1, adj);
}

int dfs(vector<bool> &hasApple, int node, int parent, vector<int> adj[])
{
    int time = 0;
    for (int child : adj[node])
    {
        if (child == parent)
            continue;
        else
        {
            int timeForChild = dfs(hasApple, child, node, adj);
            if (timeForChild > 0 || hasApple[child])
                time += timeForChild + 2;
        }
    }
    return time;
}
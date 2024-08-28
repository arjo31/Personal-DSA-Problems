/*We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.*/

#include <bits/stdc++.h>
using namespace std;

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<int> adj[n + 1];
    for (auto it : dislikes)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n + 1, -1);
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(i, color, adj))
                return false;
        }
    }
    return true;
}

bool bfs(int node, vector<int> &color, vector<int> adj[])
{
    color[node] = 1;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (color[v] == color[u])
                return false;
            if (color[v] == -1)
            {
                q.push(v);
                color[v] = !color[u];
            }
        }
    }
    return true;
}
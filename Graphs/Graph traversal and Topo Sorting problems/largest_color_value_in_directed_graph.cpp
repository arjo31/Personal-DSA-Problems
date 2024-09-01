/*There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.*/

#include <bits/stdc++.h>
using namespace std;

int largestPathValue(string colors, vector<vector<int>> &edges)
{
    int n = colors.size();
    vector<int> adj[n];
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto v : adj[i])
            indegree[v]++;
    }
    queue<int> q;
    vector<vector<int>> dist(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            dist[i][colors[i] - 'a'] = 1;
        }
    }
    int countNodes = 0;
    int maxColorValue = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        countNodes++;
        maxColorValue = max(maxColorValue, dist[u][colors[u] - 'a']);
        for (int v : adj[u])
        {
            for (int i = 0; i < 26; i++)
            {
                dist[v][i] = max(dist[v][i], dist[u][i] + ((colors[v] - 'a') == i));
            }
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    return (countNodes < n) ? -1 : maxColorValue;
}
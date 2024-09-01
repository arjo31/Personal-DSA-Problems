/*You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.*/

#include <bits/stdc++.h>
using namespace std;

int result = -1;

void dfs(int u, vector<int> &edges, vector<bool> &vis, vector<int> &count, vector<bool> &inRecursion)
{
    if (u != -1)
    {
        vis[u] = 1;
        inRecursion[u] = 1;
        int v = edges[u];
        if (v != -1 && !vis[v])
        {
            count[v] = count[u] + 1;
            dfs(v, edges, vis, count, inRecursion);
        }
        else if (v != -1 && vis[v] && inRecursion[v])
        {
            result = max(result, count[u] - count[v] + 1);
        }

        inRecursion[u] = 0;
    }
}

int longestCycle(vector<int> &edges)
{
    int n = edges.size();
    vector<bool> vis(n, false);
    vector<bool> inRecursion(n, false);
    vector<int> count(n, 1);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, edges, vis, count, inRecursion);
    }
    return result;
}
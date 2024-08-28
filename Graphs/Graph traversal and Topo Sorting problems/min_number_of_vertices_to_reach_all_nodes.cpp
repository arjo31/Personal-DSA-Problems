/*Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.*/

// Answer : All vertices with indegree 0 form the set.

#include <bits/stdc++.h>
using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
        for (int v : adj[i])
            indegree[v]++;
    vector<int> minCover;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            minCover.push_back(i);
    }
    return minCover;
}
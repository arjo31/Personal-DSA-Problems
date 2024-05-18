/*There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.*/

#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<int> adj[n + 1];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> q;
    q.push(source);
    vector<int> vis(n + 1, 0);
    vis[source] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                q.push(adjNode);
                vis[adjNode] = 1;
            }
        }
    }
    return vis[destination];
}
/*You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.*/

#include <bits/stdc++.h>
using namespace std;

int closestMeetingNode(vector<int> &edges, int node1, int node2)
{
    int n = edges.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int u = i;
        int v = edges[i];
        if (v != -1)
            adj[u].push_back(v);
    }

    vector<int> dist1(n, 1e9);
    vector<int> dist2(n, 1e9);

    bfs(node1, dist1, adj);
    bfs(node2, dist2, adj);

    int minAns = INT_MAX;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int maxDist = max(dist1[i], dist2[i]);
        if (maxDist < minAns)
        {
            minAns = maxDist;
            index = i;
        }
    }
    return (minAns == 1e9) ? -1 : index;
}

void bfs(int node, vector<int> &dist, vector<int> adj[])
{
    dist[node] = 0;
    queue<pair<int, int>> q;
    q.push({node, 0});
    while (!q.empty())
    {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        for (int v : adj[u])
        {
            if (d + 1 < dist[v])
            {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
}
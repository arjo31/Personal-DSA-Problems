#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (int adjNode : adj[node])
    {
        if (!vis[adjNode])
            dfs(adjNode, adj, vis);
    }
}

bool keysAndRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<int> adj[n];

    for (int i = 0; i < n; i++)
    {
        for (int room : rooms[i])
        {
            if (i != room)
                adj[i].push_back(room);
        }
    }
    vector<int> vis(n, 0);
    dfs(0, adj, vis);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            return false;
    return true;
}
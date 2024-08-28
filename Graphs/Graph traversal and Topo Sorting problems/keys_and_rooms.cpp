/*There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
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
    {
        if (!vis[i])
            return false;
    }
    return true;
}
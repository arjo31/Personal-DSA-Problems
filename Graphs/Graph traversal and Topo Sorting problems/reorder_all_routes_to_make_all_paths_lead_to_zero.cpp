/*There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
set<pair<int, int>> s;

int minReorder(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    vis.assign(n, 0);
    for (auto it : connections)
    {
        int u = it[0];
        int v = it[1];
        s.insert({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int minChanges = 0;
    dfs(0, minChanges, adj);
    return minChanges;
}

void dfs(int city, int &minChanges, vector<int> adj[])
{
    vis[city] = 1;
    for (int neighbor : adj[city])
    {
        if (vis[neighbor])
            continue;
        else
        {
            if (s.count({neighbor, city}) == 0)
                minChanges++;
            s.insert({neighbor, city});
            dfs(neighbor, minChanges, adj);
        }
    }
}
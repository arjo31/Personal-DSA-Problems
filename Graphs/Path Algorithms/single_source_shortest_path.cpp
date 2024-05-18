#include <bits/stdc++.h>
using namespace std;

//This is for undirected graph

vector<int> shortestPath(int V, int E, vector<vector<int>>&edges, int source)
{
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int>vis(V,0);
    queue<pair<int,int>>q;
    q.push({source,0});
    vis[source] = 1;
    vector<int>dist(V,-1);
    dist[source] = 0;
    while (!q.empty())
    {
        int node = q.front().first;
        int wt = q.front().second;
        q.pop();
        
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it,wt+1});
                dist[it] = wt+1;
            }
        }
    }
    return dist;
}
#include<bits/stdc++.h>
using namespace std;

//We have to print the shortest path from source 1 to destination n. It is a 1- indexed graph
//Print - 1 if no path exists

vector<int> shortestPath(int V, vector<vector<int>>&edges, int E)
{
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>p;
    vector<pair<int,int>> adj[V+1];
    for (int i = 0 ; i < E; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    vector<int> dist(V+1,1e9);
    vector<int> parent(V+1);
    for (int i = 1; i <= V ; i++)
    {
        parent[i] = i;
    }
    dist[1] = 0;
    p.push({0,1});
    while (!p.empty())
    {
        int dis = p.top().first;
        int node = p.top().second;
        p.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;
            if (wt + dis < dist[adjNode])
            {
                dist[adjNode] = wt + dis;
                p.push({dist[adjNode],adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if (dist[V]==1e9) return {-1};
    vector<int>path;
    int node = V;
    while (parent[node]!=node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;
}
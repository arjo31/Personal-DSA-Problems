#include <bits/stdc++.h>
using namespace std;

/*Given a weighted, undirected, and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.*/

//TC = O(ElogE)

int minimumSpanningTreePrims(vector<vector<int>>& edges, int V)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p;
    vector<int>vis(V,0);
    vector<pair<int,int>>adj[V];
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      int wt = edges[i][2];
      adj[u].push_back({v,wt});
      adj[v].push_back({u,wt});
    }
    //{wt,node}
    p.push({0,0});
    int sum = 0;
    while (!p.empty())
    {
        int wt = p.top().first;
        int node = p.top().second;
        p.pop();

        if (vis[node]==1) continue;
        vis[node] = 1;
        sum+=wt;

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;
            if (!vis[adjNode])
            {
                p.push({edW,adjNode});
            }
        }
    }
    return sum;
}
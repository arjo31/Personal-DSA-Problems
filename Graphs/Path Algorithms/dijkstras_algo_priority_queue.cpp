#include <bits/stdc++.h>
using namespace std;

//Shortest path from source to destination in an undirected weighted graph
//Time Complexity = O(ElogV)

vector<int> dijkstrasAlgo(int V, vector<vector<int>>adj[], int source)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p; //Min heap
    vector<int> dist(V,1e9);
    dist[source] = 0;
    p.push({0,source});
    while (!p.empty())
    {
        int dis = p.top().first;
        int node = p.top().second;
        p.pop();

        for (auto it : adj[node])
        {
            int edgeweight = it[1];
            int adjNode = it[0];

            if (dis + edgeweight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeweight;
                p.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
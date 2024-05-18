#include <bits/stdc++.h>
using namespace std;

/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.*/

//1 based indexing

int netwworkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<pair<int,int>> adj[n+1];
    for (int i = 0;  i < times.size(); i++)
    {
        adj[times[i][0]].push_back({times[i][1],times[i][2]});
    }
    vector<int> dist(n+1, 1e9);
    dist[k] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
    p.push({0,k});
    while (!p.empty())
    {
        int time = p.top().first;
        int node = p.top().second;
        p.pop();

        for (auto it : adj[node])
        {
            int t = it.second;
            int adjNode = it.first;
            if (time + t < dist[adjNode])
            {
                dist[adjNode] = time + t;
                p.push({dist[adjNode],adjNode});
            }
        }
    }
    for (int i = 1; i<=n; i++)
    {
        if (dist[i]==1e9) return -1;
    }
    return *max_element(dist.begin()+1, dist.end());
}
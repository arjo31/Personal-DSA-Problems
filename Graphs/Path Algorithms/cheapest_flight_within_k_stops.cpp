/*There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.*/

#include <bits/stdc++.h>
using namespace std;

int cheapestFlights(int n, vector<vector<int>> &flights, int src, int dest, int K)
{
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < flights.size(); i++)
    {
        adj[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    while (!q.empty())
    {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if (stops > K)
            continue;
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;

            if (cost + wt < dist[adjNode] && stops <= K)
            {
                dist[adjNode] = cost + wt;
                q.push({stops + 1, {adjNode, cost + wt}});
            }
        }
    }
    if (dist[dest] == 1e9)
        return -1;
    return dist[dest];
}
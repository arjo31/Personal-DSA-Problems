/*You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.*/

#include <bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
{
    priority_queue<pair<double, int>> pq;
    vector<pair<int, double>> adj[n];
    for (int i = 0; i < edges.size(); i++)
    {
        auto edge = edges[i];
        int u = edge[0];
        int v = edge[1];
        double wt = succProb[i];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<double> dist(n, 0);
    dist[start_node] = 1;
    pq.push({1, start_node});
    while (!pq.empty())
    {
        double prob = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (prob != dist[u])
            continue;

        for (auto adjNode : adj[u])
        {
            int v = adjNode.first;
            double currProb = adjNode.second;
            if (prob * currProb > dist[v])
            {
                dist[v] = prob * currProb;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[end_node];
}
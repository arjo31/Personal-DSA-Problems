/*You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].*/

#include <bits/stdc++.h>
using namespace std;

// Memory limit exceeded
vector<vector<long long>> shortestDistances(unordered_map<char, vector<pair<char, int>>> &adj)
{
    vector<vector<long long>> dist(26, vector<long long>(26, 1e18));

    for (char src = 'a'; src <= 'z'; src++)
    {
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> pq;
        dist[src - 'a'][src - 'a'] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            long long d = pq.top().first;
            char u = pq.top().second;
            pq.pop();

            if (d > dist[src - 'a'][u - 'a'])
                continue;

            for (auto &[v, w] : adj[u])
            {
                if (d + w < dist[src - 'a'][v - 'a'])
                {
                    dist[src - 'a'][v - 'a'] = d + w;
                    pq.push({dist[src - 'a'][v - 'a'], v});
                }
            }
        }
    }
    return dist;
}

long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
{
    unordered_map<char, vector<pair<char, int>>> adj;
    for (int i = 0; i < original.size(); i++)
    {
        adj[original[i]].push_back({changed[i], cost[i]});
    }

    vector<vector<long long>> distances = shortestDistances(adj);

    long long total_cost = 0;
    for (int i = 0; i < source.size(); i++)
    {
        long long dist = distances[source[i] - 'a'][target[i] - 'a'];
        if (dist == 1e18)
            return -1;
        total_cost += dist;
    }
    return total_cost;
}

// Efficient : TC : O(26*V*logV + S)
vector<vector<long long>> shortestDistances(unordered_map<char, vector<pair<char, int>>> &adj)
{
    vector<vector<long long>> dist(26, vector<long long>(26, 1e18));

    for (char src = 'a'; src <= 'z'; src++)
    {
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> pq;
        dist[src - 'a'][src - 'a'] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            long long d = pq.top().first;
            char u = pq.top().second;
            pq.pop();

            if (d > dist[src - 'a'][u - 'a'])
                continue;

            for (auto &[v, w] : adj[u])
            {
                if (d + w < dist[src - 'a'][v - 'a'])
                {
                    dist[src - 'a'][v - 'a'] = d + w;
                    pq.push({dist[src - 'a'][v - 'a'], v});
                }
            }
        }
    }
    return dist;
}

long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
{
    unordered_map<char, vector<pair<char, int>>> adj;
    for (int i = 0; i < original.size(); i++)
    {
        adj[original[i]].push_back({changed[i], cost[i]});
    }

    vector<vector<long long>> distances = shortestDistances(adj);

    long long total_cost = 0;
    for (int i = 0; i < source.size(); i++)
    {
        long long dist = distances[source[i] - 'a'][target[i] - 'a'];
        if (dist == 1e18)
            return -1;
        total_cost += dist;
    }
    return total_cost;
}
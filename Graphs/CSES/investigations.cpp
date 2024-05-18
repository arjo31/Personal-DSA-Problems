#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>adj[n+1];

    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>>p;

    vector<long long int> dist(n+1,1e18);
    vector<long long int> noOfPaths(n+1,0);
    dist[1] = 0;
    noOfPaths[1] = 1;
    p.push({0,1});
    vector<int>longestPath(n+1,-1);
    vector<int>shortestPath(n+1,-1);
    shortestPath[1] = 0;
    longestPath[1] = 0;
    while (!p.empty())
    {
        long long int wt = p.top().first;
        int node = p.top().second;
        p.pop();

        if (dist[node] < wt) continue;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int w = it.second;
            if (wt + w < dist[adjNode])
            {
                dist[adjNode] = w + wt;
                p.push({w + wt, adjNode});
                noOfPaths[adjNode] = noOfPaths[node];
                longestPath[adjNode] = longestPath[node] + 1;
                shortestPath[adjNode] = shortestPath[node] + 1;
            }
            else if (wt + w == dist[adjNode])
            {
                noOfPaths[adjNode] = (noOfPaths[node] + noOfPaths[adjNode]) % MOD;
                shortestPath[adjNode] = min(shortestPath[adjNode], shortestPath[node] + 1);
                longestPath[adjNode] = max(longestPath[adjNode], longestPath[node] + 1);
            }
        }
    }
    long long int minWeight = dist[n];
    long long int noOfMinWeightPaths = noOfPaths[n];
    long long int shortestMinWeightPath = shortestPath[n];
    long long int longestMinWeightPath = longestPath[n];
    cout<<minWeight<<" "<<noOfMinWeightPaths<<" "<<shortestMinWeightPath<<" "<<longestMinWeightPath<<endl;
    return 0;
}
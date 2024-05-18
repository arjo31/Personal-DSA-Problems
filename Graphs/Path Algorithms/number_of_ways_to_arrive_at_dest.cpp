#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>&roads)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p;
    p.push({0,0});
    vector<int> dist(n,1e9);
    dist[0] = 0;
    vector<pair<int,int>>adj[n];
    for (int i = 0; i < roads.size(); i++)
    {
        adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
    }
    vector<int> ways(n,0);
    ways[0] = 1;
    while (!p.empty())
    {
        int node = p.top().second;
        int dis = p.top().first;
        p.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;
            if (wt + dis < dist[adjNode])
            {
                dist[adjNode] = wt + dis;
                p.push({dist[adjNode],adjNode});
                ways[adjNode] = ways[node];
            }
            else if (wt + dis == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node])%(int)(1e9+7);
            }
        }
    }
    return ways[n-1];
}

int main()
{
    vector<vector<int>>roads = {
        {0,1,4},
        {1,3,5},
        {2,1,7}
    };
    cout<<countPaths(4,roads)<<endl;
    return 0;
}
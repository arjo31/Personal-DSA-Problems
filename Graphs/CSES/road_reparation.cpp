#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p;
    p.push({0,1});
    vector<int>vis(n+1,0);
    long long int sum = 0;
    while (!p.empty())
    {
        int wt = p.top().first;
        int node = p.top().second;
        p.pop();

        if (vis[node]) continue;
        vis[node] = 1;
        sum+=wt;

        for (auto it : adj[node])
        {
            int w = it.second;
            int adjNode = it.first;
            if (!vis[adjNode])
            {
                p.push({w,adjNode});
            }
        }
    }
    cout<<((vis[n]!=0) ? to_string(sum) : "IMPOSSIBLE")<<endl;
    return 0;
}
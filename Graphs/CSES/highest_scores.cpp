#include <bits/stdc++.h>
using namespace std;

const long long int inf = 1e17;
const long long int ninf = -1e17;

int main()
{
    long long int n,m;
    cin>>n>>m;
    vector<vector<long long int>>edges(m,vector<long long int>(3));
    for (long long int i = 0; i < m; i++)
    {
        long long int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w*(-1)});
    }
    vector<long long int> dist(n+1, inf);
    dist[1] = 0;
    for (long long int i = 0; i<n; i++)
    {
        for (auto it : edges)
        {
            long long int u = it[0];
            long long int v = it[1];
            long long int wt = it[2];
            if (dist[u]==inf) continue;
            dist[v] = min(dist[v],dist[u]+wt);
            dist[v] = max(dist[v],ninf);
        }
    }
    for (long long int i = 0; i<n; i++)
    {
        for (auto it : edges)
        {
            long long int u = it[0];
            long long int v = it[1];
            long long int wt = it[2];
            if (dist[u]==inf) continue;
            dist[v] = max(dist[v],ninf);
            if (dist[v] > dist[u]+wt)
            {
                dist[v] = ninf;
            }
        }
    }
    
    if (dist[n]==ninf || dist[n]==inf) cout<<-1<<endl;
    else cout<<dist[n]*(-1)<<endl;
    return 0;
}
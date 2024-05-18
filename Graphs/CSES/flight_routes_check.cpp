#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<int>&vis, vector<int>adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it]) dfs1(it,vis,adj);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>vis(n+1,0);

    dfs1(1,vis,adj);

    for (int i = 1; i<=n; i++)
    {
        if (!vis[i])
        {
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }

    vis.assign(n+1,0);

    vector<int>adjT[n+1];
    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    dfs1(1,vis,adjT);

    for (int i = 1; i<=n; i++)
    {
        if (!vis[i])
        {
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
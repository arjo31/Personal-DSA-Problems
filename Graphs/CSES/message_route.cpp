#include <bits/stdc++.h>
using namespace std;

int ans = 0;
 
void bfs(int node, vector<int>&vis, vector<int>adj[],priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>&p,vector<int>&parent,vector<int>&path,int n)
{
    vis[node] = 1;
    p.push({1,node});
    parent[node] = -1;
    while (!p.empty())
    {
        int steps = p.top().first;
        int v = p.top().second;
        p.pop();
        if (v==n)
        {
            cout<<steps<<endl;
            int index = n;
            while (index!=1)
            {
                path.push_back(index);
                index = parent[index];
            }
            path.push_back(1);
            reverse(path.begin(),path.end());
            for (auto it : path)
            {
                cout<<it<<" ";
            }
            return;
        }
 
        for (auto it : adj[v])
        {
            if (!vis[it])
            {
                p.push({steps+1, it});
                vis[it] = 1;
                parent[it] = v;
            }
        }
    }
}
 
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n+1,0);
    vector<int>parent(n+1);
    vector<int>path;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            count++;
            if (count > 1)
            {
                cout<<"IMPOSSIBLE"<<endl;
                exit(0);
            }
            bfs(i,vis,adj,p,parent,path,n);
        }
    }
    cout<<endl;
    return 0;
}
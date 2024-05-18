#include <bits/stdc++.h>
using namespace std;

vector<int>ans;

void bfs(int node, vector<int> adj[], vector<int>&vis, queue<int>&q)
{   
    ans.push_back(node);
    vis[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto it : adj[v])
        {
            if (vis[it]==0)
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    queue<int>q;
    int count = 0;
    for (int i = 1; i <=n ;i++)
    {
        if (vis[i]==0)
        {
            count++;
            bfs(i,adj,vis,q);
        }
    }
    cout<<count-1<<endl;
    for (int i = 0 ; i < ans.size() - 1; i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    cout<<endl;
    return 0;
}
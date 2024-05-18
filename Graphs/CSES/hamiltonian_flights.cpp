#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
 
void dfs(int curr, int parent, vector<int>&vis, vector<int>adj[], long long int &count,int& visitedNodes, int n)
{
    vis[curr] = 1;
    visitedNodes++;
    if (curr==n && visitedNodes==n) count = (count + 1)%MOD;
    
    for (auto adjNode : adj[curr])
    {
        if (!vis[adjNode])
        {
            dfs(adjNode,curr,vis,adj,count,visitedNodes,n);
        }
    }
    vis[curr] = 0;
    visitedNodes--;
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>vis(n+1,0);
    long long int count = 0;
    int visitedNodes = 0;
    dfs(1,0,vis,adj,count,visitedNodes,n);
    cout<<count<<endl;
    return 0;
}
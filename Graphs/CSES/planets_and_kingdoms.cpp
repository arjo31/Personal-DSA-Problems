#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adj[],vector<int>&vis, stack<int>&st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it]) dfs(it,adj,vis,st);
    }
    st.push(node);
}

void dfs2(int node, vector<int>adjT[],vector<int>&vis,vector<int>&kingdoms, int &count)
{
    vis[node] = 1;
    kingdoms[node] = count;
    for (auto it : adjT[node])
    {
        if (!vis[it]) dfs2(it,adjT,vis,kingdoms,count);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    stack<int>st;
    vector<int>adj[n+1];
    for (int i = 0 ;i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    //First DFS call
    vector<int> vis(n+1,0);
    for (int i = 1; i <=n; i++)
    {
        if (!vis[i])
        {
            dfs(i,adj,vis,st);
        }
    }
    //Reverse the edges
    vector<int> adjT[n+1];
    for (int i = 1; i<=n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    //Apply dfs again
    int count = 0;
    vector<int>kingdoms(n+1,0);
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            count++;
            dfs2(node,adjT,vis,kingdoms,count);
        }
    }
    cout<<count<<endl;
    for (int i = 1; i<=n; i++) cout<<kingdoms[i]<<" ";
    cout<<endl;
    return 0;
}
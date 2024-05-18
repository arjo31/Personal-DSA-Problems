#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//O(n^2)
// void countPaths(int node, vector<int>&vis, vector<int>adj[],long long int &count, int n)
// {
//     if (node==n)
//     {
//         count = (count+1)%MOD;
//         return ;
//     }
//     vis[node] = 1;
//     for (auto it : adj[node])
//     {
//         if (!vis[it])
//         {
//             countPaths(it,vis,adj,count,n);
//         }
//     }
//     vis[node] = 0;
// }

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
    vector<int>adjT[n+1];
    for (int i = 1; i<=n; i++)
    {
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }
    vector<int>dp(n+1,0);
    dp[n] = 1;
    vector<int>indegree(n+1,0);
    for (int i = 1; i<=n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }   
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i]==0) q.push(i);
    }
    vector<int>list;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        list.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it]==0) q.push(it);
        }
    }
    reverse(list.begin(),list.end());

    for (int i = 0; i < list.size(); i++)
    {
        for (auto it : adjT[list[i]])
        {
            dp[it] = (dp[it] + dp[list[i]]) % MOD;
        }
    }
    cout<<dp[1]<<endl;
    return 0;
}
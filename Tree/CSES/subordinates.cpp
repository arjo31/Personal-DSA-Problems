#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int>adj[],vector<int>&count)
{
    count[node] = 1;
    for (auto it : adj[node])
    {
        dfs(it,node,adj,count);
        count[node]+=count[it];
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for (int i = 1; i<n; i++)
    {
        int u;
        cin>>u;
        adj[u].push_back(i+1);
    }
    vector<int>count(n+1);
    dfs(1,-1,adj,count);
    for (int i = 1; i <= n; i++)
    {
        cout<<count[i] - 1<<" ";
    }
    cout<<endl;
    return 0;
}

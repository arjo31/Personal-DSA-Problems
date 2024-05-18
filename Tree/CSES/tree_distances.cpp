#include <bits/stdc++.h>
using namespace std;

//dist[0][i] = dist from a to i
//dist[1][i] = dist from b to i
int d[2][200001];

void dfs(int curr, int parent, vector<int>adj[],vector<int>&dist,int i)
{
    //current node op after entering
    d[i][curr] = dist[curr];
    for (auto child : adj[curr])
    {
        if (child==parent) continue;
        //child node operation before entering
        dist[child] = dist[curr] + 1;
        dfs(child, curr,adj,dist,i);
        //child node operation after exiting
    }
    //current node operation before exiting
}

int main()
{
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for (int i = 0; i< n -1; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dist(n+1,0);
    dfs(1,0,adj,dist,0);
    int maxNode_a;
    int maxDist = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxDist<=dist[i])
        {
            maxDist = dist[i];
            maxNode_a = i;
        }
        dist[i] = 0;
    }
    dfs(maxNode_a,0,adj,dist,0);

    maxDist = 0;
    int maxNode_b;
    for (int i = 1; i <= n; i++)
    {
        if (maxDist<=dist[i])
        {
            maxDist = dist[i];
            maxNode_b = i;
        }
        dist[i] = 0;
    }

    dfs(maxNode_b,0,adj,dist,1);

    for (int i = 1; i<=n; i++)
    {
        cout<<max(d[0][i], d[1][i])<<" ";
    }
    return 0;
}
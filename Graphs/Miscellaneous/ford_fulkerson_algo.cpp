//Used for maximum flow problems. TE : O(E*Flow)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int bfs(int src, int target,int V, vector<int>&parent, vector<vector<int>>&graph)
{
    fill(parent.begin(), parent.end(), -1);
    parent[src] = -2;
    queue<pair<int,int>>q;
    q.push({src,1e9});

    while (!q.empty())
    {
        int u = q.front().first;
        int cap = q.front().second;

        q.pop();

        for (int v = 1; v<=V; v++)
        {
            if (u!=v && parent[v]==-1 && graph[u][v]!=0)
            {
                parent[v] = u;
                int maxCap = graph[u][v];
                int minCap = min(cap, maxCap);
                if (v==target) return minCap;
                q.push({v,minCap});
            }
        }
    }
    return 0;
}

int fordFulkerson(int src, int target,int V, vector<vector<int>>&graph)
{
    vector<int>parent(V+1,-1);

    int maxFlow = 0;
    int minCap = 0;

    while (minCap = bfs(src,target,V,parent,graph))
    {
        maxFlow+=minCap;
        int v = target;

        while (v!=src)
        {
            int u = parent[v];
            graph[u][v]-=minCap;
            graph[v][u]+=minCap;
            v = u;
        }
    }
    return maxFlow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1,vector<int>(n+1,0));
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = w;
    }
    cout<<fordFulkerson(1,n,n,graph);
    return 0;
}
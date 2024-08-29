#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    public:
        vector<int> parent,size,rank;
        DisjointSet(int V)
        {
            parent.resize(V+1);
            size.resize(V+1,1);
            rank.resize(V+1,0);
            for (int i = 0; i <=V ; i++)
            {
                parent[i] = i;
            }
        }

        int findUParent(int node)
        {
            if (node==parent[node])
            {
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v)
        {
            u = findUParent(u);
            v = findUParent(v);
            if (u==v) return;
            if (rank[u] < rank[v])
            {
                parent[u] = v;
            }
            else if(rank[u] > rank[v])
            {
                parent[v] = u;
            }
            else
            {
                parent[v] = u;
                rank[u]++;
            }
        }

        void unionBySize(int u, int v)
        {
            u = findUParent(u);
            v = findUParent(v);
            if (u==v) return;
            if (size[u] < size[v])
            {
                size[v]+=size[u];
                parent[u] = v;
            }
            else
            {
                size[u]+=size[v];
                parent[v] = u;
            }
        }
};

void bfs(int node, vector<int> adj[], queue<int>&q, vector<int>&vis)
{
    vis[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        for (auto it : adj[n])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}

int noOfConnectedComponents(int V, vector<vector<int>>&connections)
{
    int countConnectedComponents = 0;
    vector<int> vis(V,0);
    queue<int>q;
    vector<int> adj[V];
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < V ; i++)
    {
        if (vis[i]==0)
        {
            countConnectedComponents++;
            bfs(i,adj,q,vis);
        }
    }
    return countConnectedComponents;
}

int noOfConnectedComponentsUsingDS(int V, vector<vector<int>>&connections)
{
    DisjointSet ds(V);
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        if (ds.findUParent(u)!=ds.findUParent(v))
        {
            ds.unionByRank(u,v);
        }
    }
    int countConnectedComponents = 0;
    for (int i = 0; i < V; i++)
    {
        if (ds.parent[i]==i) countConnectedComponents++;
    }
    return countConnectedComponents;    
}

int makeConnected(int V, vector<vector<int>>&connections)
{
    int c = noOfConnectedComponents(V,connections) - 1;
    DisjointSet ds(V);
    int extraEdge = 0;
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        if (ds.findUParent(u)!=ds.findUParent(v))
        {
            ds.unionByRank(u,v);
        }
        else
        {
            extraEdge++;
        }
    }
    if (extraEdge>=c)
    {
        return c;
    }
    return -1;
}
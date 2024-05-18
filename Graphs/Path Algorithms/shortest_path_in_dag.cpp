#include <bits/stdc++.h>
using namespace std;

//Find the shortest path from source 0 to all the vertex. We will be using topological sort

//Step 1 - Topo sort
//Step 2 - Take the nodes from the stack/queue and relax the edges. Create a distance array and mark it as infinity. Make the source node 0 in the distance array.

void topoSort(int node, vector<pair<int,int>>adj[], int vis[],stack<int>& st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
        {
            topoSort(v,adj,vis,st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int V,int E, vector<int>edges[])
{
    vector<pair<int,int>>adj[V];
    for (int i = 0; i < E ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
    }
    int vis[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            topoSort(i,adj,vis,st);
        }
    }
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
    {
        if (st.top()!=0)
        {
            int node = st.top();
            st.pop();
            dist[node] = -1;
        }
    }
    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;
}

//Using Kahn's algo

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int,int>> adj[n];
    for (int i = 0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
    }
    int indegree[n] = {0};
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it.first]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i]==0) q.push(i);
    }
    vector<int>ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node]) {
            indegree[it.first]--;
            if (indegree[it.first] == 0)
              q.push(it.first);
        }
    }
    vector<int> dist(n, INT_MAX);
    dist[ans[0]] = 0;
    for (int i = 0; i < n; i++)
    {
        int node = ans[i];
        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            if (wt + dist[node] < dist[v])
            {
                dist[v] = wt + dist[node];
            }
        }
    }
    return dist;
}
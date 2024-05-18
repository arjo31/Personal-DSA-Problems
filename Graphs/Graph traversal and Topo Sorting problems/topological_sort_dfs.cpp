#include <bits/stdc++.h>
using namespace std;

//Topological sorting is basically a linear ordering of vertices in a directed acyclic graph such that if there is an edge between u and v, u appears before v in that ordering. There can be multiple answers. Stack is used

void dfs(int node, int vis[],vector<int> adj[],stack<int> &s)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it,vis,adj,s);
        }
    }
    s.push(node);
}

vector<int>topologicalSort(int V, vector<int>adj[])
{
    int vis[V] = {0};
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i,vis,adj,s);
        }
    }
    vector<int>ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
#include <bits/stdc++.h>
using namespace std;

//This algo is used to find out strongly connected components in a graph
//SCC's are valid only for directed graphs
//A strongly connected component is the component of a directed graph that has a path from every vertex to every other vertex in that component
//Number of SCC's
//Time Complexity = O(V+E) (DFS) + O(V+E) (Transposing graph) + O(V+E) (dfs again)

void dfs(int node, vector<int>&vis, vector<int>adj[], stack<int>&st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}

void dfs3(int node, vector<int> &vis, vector<int>adjT[])
{
    vis[node] = 1;
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs3(it,vis,adjT);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    //Sort all the nodes acc to finishing time
    vector<int> vis(V,0);
    stack<int>st;
    for(int i = 0; i <V; i++)
    {
        if (!vis[i])
        {
            dfs(i,vis,adj,st);
        }
    }

    //Reverse the graph
    vector<int> adjT[V];
    for(int i = 0; i < V ; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            //Currently : i - > it
            //To make : it - > i;
            adjT[it].push_back(i);
        }
    }

    //Perform dfs on order of finishing time
    int scc = 0;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            dfs3(node,vis,adjT);
        }
    }
    return scc;
}
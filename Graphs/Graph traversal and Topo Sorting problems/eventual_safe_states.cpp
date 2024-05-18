#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int source, vector<int>adj[], int vis[], int pathVis[], int check[])
{
    vis[source] = 1;
    pathVis[source] = 1;
    check[source] = 0;
    for (auto it : adj[source])
    {
        if (!vis[it])
        {
            if (dfsCheck(it,adj,vis,pathVis,check))
            {
                check[it] = 0;
            }
        }
        else if (pathVis[it])
        {
            check[it] = 0;
            return true;
        }
    }
    check[source] = 1;
    pathVis[source] = 0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int>adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};
    vector<int> safeNodes;
    for (int i = 0; i < V ; i++)
    {
        if (!vis[i])
        {
            dfsCheck(i,adj,vis,pathVis,check);
        }
    }
    for (int i = 0; i < V ; i++)
    {
        if (check[i]) safeNodes.push_back(i);
    }
    return safeNodes;
}
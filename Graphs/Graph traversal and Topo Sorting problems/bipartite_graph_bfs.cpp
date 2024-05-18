#include <bits/stdc++.h>
using namespace std;

//Another wording of the problem. Color the graph with 2 colors such that no two adjacent nodes are the same color

bool check(int start,int V, vector<int> adj[], int color[])
{
    queue<int>q;
    q.push(start);
    color[start] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it]==-1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
    }
    return true; 
}

bool isBipartite(int V, vector<int> adj[])
{
    int color[V];
    for (int i = 0 ; i < V ; i++)
    {
        color[i] = -1;
    }
    for (int i = 0; i < V; i++)
    {
        if (color[i]==-1)
        {
            if (!check(i,V,adj,color)) return false;
        }
    }
    return true;
}
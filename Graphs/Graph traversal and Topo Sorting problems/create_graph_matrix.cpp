#include <bits/stdc++.h>
using namespace std;

// n = number of nodes, m = no of edges. Any connected graph must have atleast n-1 edges to connect the vertices. Also if f = number of faces, then f+n = m+2.
// m lines represent edges

int main()
{
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];
    for (int i = 0; i < m ;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}
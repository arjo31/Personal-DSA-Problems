#include <bits/stdc++.h>
using namespace std;

//It basically counts the number of connected components in a graph

void bfs(vector<bool>&vis, int node, vector<vector<int>>&isConnected)
{
    queue<int>q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[node][j] and !vis[j])
            {
                q.push(j);
                vis[j] = 1;
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected)
{
    int n = isConnected.size();
    int count = 0;
    vector<bool>vis(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            count++;
            bfs(vis,i,isConnected);
        }
    }
    return count;
}
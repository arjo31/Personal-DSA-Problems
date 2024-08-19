/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.*/

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<bool> &vis, int node, vector<vector<int>> &isConnected)
{
    queue<int> q;
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

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    int count = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            count++;
            bfs(vis, i, isConnected);
        }
    }
    return count;
}
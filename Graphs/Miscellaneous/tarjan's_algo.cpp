#include <bits/stdc++.h>
using namespace std;

int timer = 1;
//finds bridges in graph
//Helps find the strongly connected components

void dfs(int node, int parent, vector<int>&vis, vector<int>adj[],vector<int>&timeIn, vector<int>&lowTime,vector<vector<int>>&bridges)
{
    vis[node] = 1;
    timeIn[node] = lowTime[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (it==parent)
        {
            continue;
        }
        if (vis[it]==0)
        {
            dfs(it,node,vis,adj,timeIn,lowTime,bridges);
            lowTime[node] = min(lowTime[node],lowTime[it]);
            if (lowTime[it] > timeIn[node])
            {
                bridges.push_back({it,node});
            }
        }
        else
        {
            lowTime[node] = min(lowTime[node],lowTime[it]);
        }
    }
}

vector<vector<int>>criticalConnections(int n, vector<vector<int>>&connections)
{
    vector<int>adj[n];
    for(auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n,0);
    vector<int> timeIn(n);
    vector<int> lowTime(n);
    vector<vector<int>>bridges;
    dfs(0,-1,vis,adj,timeIn,lowTime,bridges);
    return bridges;
}
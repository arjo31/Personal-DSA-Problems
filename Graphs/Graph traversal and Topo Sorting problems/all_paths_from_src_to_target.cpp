/*Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> ans;
vector<int> path;

void dfs(int node, vector<vector<int>> &graph, vector<int> &vis)
{
    if (node == n - 1)
    {
        path.push_back(node);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    vis[node] = 1;
    path.push_back(node);
    for (int adjNode : graph[node])
    {
        if (!vis[adjNode])
        {
            dfs(adjNode, graph, vis);
        }
    }
    vis[node] = 0;
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    n = graph.size();
    vector<int> vis(n, 0);
    dfs(0, graph, vis);
    return ans;
}
#include <bits/stdc++.h>
using namespace std;

//Topological sorting using bfs. We will use the concept of indegree, which is the number of incoming edges to a node.

vector<int> kahnAlgo(int V, vector<int>adj[])
{
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it: adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V ; i++)
    {
        if (indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it:adj[node])
        {
            indegree[it]--;
            if (indegree[it]==0) q.push(it);
        }
    }
    return ans;
}
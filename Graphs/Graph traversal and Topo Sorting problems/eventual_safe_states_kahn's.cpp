#include <bits/stdc++.h>
using namespace std;

//A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending

//Reverse the edges and then apply topological sort.

vector<int> safeStates(int V, vector<int> adj[])
{
    vector<int> adjRev[V];
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int>q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i]==0) q.push(i);
    }
    vector<int>ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adjRev[node])
        {
            indegree[it]--;
            if (indegree[it]==0) q.push(it);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
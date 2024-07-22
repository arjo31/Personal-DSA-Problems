/*You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
    vector<int> indegree(n, 0);
    vector<int> adj[n];

    for (auto &e : edges)
    {
        int v = e[0], w = e[1];
        adj[v].push_back(w);
        indegree[w]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<vector<int>> ancestor(n);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int w : adj[v])
        {
            auto &aw = ancestor[w];
            aw.push_back(v);
            for (int num : ancestor[v])
                aw.push_back(num);

            sort(aw.begin(), aw.end());
            int sz = 1, az = aw.size();

            for (int i = 1; i < az; i++)
            {
                if (aw[i] != aw[i - 1])
                    aw[sz++] = aw[i];
            }
            aw.resize(sz);

            if (--indegree[w] == 0)
                q.push(w);
        }
    }

    return ancestor;
}
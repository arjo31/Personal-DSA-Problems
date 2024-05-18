/*In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (parent[node] == node)
            return node;
        return (parent[node] = findUParent(parent[node]));
    }

    void unionBySize(int u, int v)
    {
        u = findUParent(u);
        v = findUParent(v);
        if (u == v)
            return;
        if (size[u] > size[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
        else
        {
            parent[u] = v;
            size[v] += size[u];
        }
    }
};

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int m = edges.size();
    int n = m;
    vector<int> ans;
    DisjointSet ds(n);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        if (ds.findUParent(u) == ds.findUParent(v))
        {
            ans.push_back(u);
            ans.push_back(v);
        }
        else
        {
            ds.unionBySize(u, v);
        }
    }
    return ans;
}

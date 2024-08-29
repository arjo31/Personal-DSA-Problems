/*You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

long long countPairs(int n, vector<vector<int>> &edges)
{
    DisjointSet ds(n);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        if (ds.findUParent(u) != ds.findUParent(v))
            ds.unionBySize(u, v);
    }
    unordered_set<int> s;
    vector<int> sizes;
    for (int i = 0; i < n; i++)
    {
        if (!s.count(ds.findUParent(i)))
        {
            sizes.push_back(ds.size[ds.findUParent(i)]);
            s.insert(ds.findUParent(i));
        }
    }
    long long ans = 0;
    long long currSum = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        currSum += sizes[i];
        ans += (sizes[i] * (n - currSum));
    }
    return ans;
}
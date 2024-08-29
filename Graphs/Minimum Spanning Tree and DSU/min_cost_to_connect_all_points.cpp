/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
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

    int findUParent(int u)
    {
        if (parent[u] == u)
            return u;
        return (parent[u] = findUParent(parent[u]));
    }

    void unionBySize(int u, int v)
    {
        u = findUParent(u);
        v = findUParent(v);
        if (u == v)
            return;
        if (size[u] > size[v])
        {
            size[u] += size[v];
            parent[v] = u;
        }
        else
        {
            size[v] += size[u];
            parent[u] = v;
        }
    }
};

static bool comp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    vector<vector<int>> adj;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            int w = abs(x2 - x1) + abs(y2 - y1);
            adj.push_back({i, j, w});
        }
    }
    sort(adj.begin(), adj.end(), comp);

    DisjointSet ds(n);
    int minPoints = 0;
    int count = 0;
    for (int i = 0; i < adj.size(); i++)
    {
        int u = adj[i][0];
        int v = adj[i][1];
        int w = adj[i][2];
        if (ds.findUParent(u) != ds.findUParent(v))
        {
            ds.unionBySize(u, v);
            minPoints += w;
            count++;
        }
        if (count == n - 1)
            break;
    }
    return minPoints;
}
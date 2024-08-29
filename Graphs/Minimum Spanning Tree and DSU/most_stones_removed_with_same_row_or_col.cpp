/*On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size, rank;
    DisjointSet(int V)
    {
        parent.resize(V + 1);
        rank.resize(V + 1, 0);
        size.resize(V + 1, 1);
        for (int i = 0; i <= V; i++)
        {
            parent[i] = i;
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

    void unionByRank(int u, int v)
    {
        u = findUParent(u);
        v = findUParent(v);
        if (u == v)
            return;
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        u = findUParent(u);
        v = findUParent(v);
        if (u == v)
            return;
        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

//[[0,0],[0,2],[1,1],[2,0],[2,2]]
// MAtrix :
// S 0 S
// 0 S 0
// S 0 S

int removeStones(vector<vector<int>> &stones)
{
    int noOfStones = stones.size();
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> mpp;
    for (auto it : stones)
    {
        int row = it[0];
        int col = it[1] + maxRow + 1;
        if (ds.findUParent(row) != ds.findUParent(col))
        {
            ds.unionBySize(row, col);
            mpp[row] = 1;
            mpp[col] = 1;
        }
    }
    int count = 0;
    for (auto it : mpp)
    {
        if (ds.findUParent(it.first) == it.first)
        {
            count++;
        }
    }

    return noOfStones - count;
}

// DFS
int n;
void dfs(vector<vector<int>> &stones, int index, vector<bool> &visited)
{
    visited[index] = true;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1])))
        {
            dfs(stones, i, visited);
        }
    }
}

int removeStones(vector<vector<int>> &stones)
{
    n = stones.size();
    vector<bool> visited(n, false);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        dfs(stones, i, visited);
        count++;
    }

    return n - count;
}
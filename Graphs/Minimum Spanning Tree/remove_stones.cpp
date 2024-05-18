#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    public:
        vector<int> parent,size,rank;
        DisjointSet(int V)
        {
            parent.resize(V+1);
            rank.resize(V+1,0);
            size.resize(V+1,1);
            for (int i = 0; i<=V; i++)
            {
                parent[i] = i;
            }
        }

        int findUParent(int node)
        {
            if (node==parent[node])
            {
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v)
        {
            u = findUParent(u);
            v = findUParent(v);
            if (u==v) return ;
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
            if (u==v) return;
            if (size[u] < size[v])
            {
                parent[u] = v;
                size[v]+=size[u];
            }
            else
            {
                parent[v] = u;
                size[u]+=size[v];
            }
        }
};

//[[0,0],[0,2],[1,1],[2,0],[2,2]]
//MAtrix : 
//S 0 S
//0 S 0
//S 0 S

int removeStones(vector<vector<int>>& stones)
{
    int noOfStones = stones.size();
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones)
    {
        maxRow = max(maxRow,it[0]);
        maxCol = max(maxCol,it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int,int>mpp;
    for (auto it : stones)
    {
        int row = it[0];
        int col = it[1] + maxRow + 1;
        if (ds.findUParent(row)!=ds.findUParent(col))
        {
            ds.unionBySize(row,col);
            mpp[row] = 1;
            mpp[col] = 1;
        }        
    }
    int count = 0;
    for (auto it : mpp)
    {
        if (ds.findUParent(it.first)==it.first)
        {
            count++;
        }
    }
    
    return noOfStones - count;
}
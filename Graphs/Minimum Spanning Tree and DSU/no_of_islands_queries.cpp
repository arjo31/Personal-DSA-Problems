#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1,0,1,0};
vector<int> dcol = {0,1,0,-1};

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

bool isValid(int adjRow, int adjCol, int n, int m)
{
    return ((adjRow>=0 && adjRow<n) && (adjCol>=0 && adjCol<m));
}

vector<int> noOfIslands(int n, int m, vector<vector<int>>&operators)
{
    DisjointSet ds(n*m);
    vector<vector<int>> vis(n, vector<int>(m,0));
    int count = 0;
    vector<int> ans;
    for(auto it : operators)
    {
        int row = it[0];
        int col = it[1];
        if (vis[row][col]==1)
        {
            ans.push_back(count);
            continue;
        }
        vis[row][col] = 1;
        count++;

        for (int i = 0 ; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (isValid(nrow,ncol,n,m) && vis[nrow][ncol]==1)
            {
                int node = row*m+col;
                int adjNode = nrow*m+ncol;
                if (ds.findUParent(node)!=ds.findUParent(adjNode))
                {
                    count--;
                    ds.unionBySize(node,adjNode);
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}
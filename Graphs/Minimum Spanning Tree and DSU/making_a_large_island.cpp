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

int makeBigIsland(vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();
    DisjointSet ds(n*m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j]==0) continue;
            for(int k = 0; k < 4; k++)
            {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];
                if (isValid(nrow,ncol,n,m) && grid[nrow][ncol]==1)
                {
                    int node = i*m + j;
                    int adjNode = nrow*m + ncol;
                    ds.unionBySize(node,adjNode);
                }
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m ; j++)
        {
            if (grid[i][j]==1) continue;
            set<int> st;
            for(int k = 0; k < 4; k++)
            {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];
                if (isValid(nrow,ncol,n,m))
                {
                    if (grid[nrow][ncol]==1)
                    {
                        st.insert(ds.findUParent(nrow*m + ncol));
                    }
                }
            }
            int size = 1;
            for (auto it : st)
            {
                size+=ds.size[it];
            }
            mx = max(mx,size);
        }
    }
    for(int i = 0; i < n*m; i++)
    {
        mx = max(mx,ds.size[ds.findUParent(i)]);
    }
    return mx;
}
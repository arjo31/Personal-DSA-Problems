#include <bits/stdc++.h>
using namespace std;

vector<int>drow = {-1,0,1,0};
vector<int>dcol = {0,1,0,-1};

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
            if (u==v) return ;
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

bool isValid(int r, int c, int n, int m)
{
    return ((r>=0 && r<n) && (c>=0 && c<m));
}

int minTimeTaken(vector<vector<int>>&grid)
{
    int n = grid.size();
    if (n==1) return 0;
    //DisjointSet ds(n*n);
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>p;
    p.push({grid[0][0],{0,0}});
    vector<vector<int>> vis(n,vector<int>(n,0));
    vis[0][0] = 1;
    int t = INT_MIN;
    while (!p.empty())
    {
        int time = p.top().first;
        int r = p.top().second.first;
        int c = p.top().second.second;
        p.pop();

        if (time > t)
        {
            t = time;
        }
        if (r==n-1 && c==n-1) return t;
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (isValid(nrow,ncol,n,n) && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                p.push({grid[nrow][ncol],{nrow,ncol}});
            }
        }
    }
    return -1;
}

//Using union find

int minTimeTaken(vector<vector<int>>&grid)
{
    unordered_map<int,pair<int,int>> ump;
    int n = grid.size();
    if(n==1) return 0;
    DisjointSet ds(n*n);
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            ump[grid[i][j]]={i,j};
    int time = 0;
    while(ds.findUParent(0)!=ds.findUParent(n*n - 1))
    {
        auto node = ump[time];
        int x = node.first;
        int y = node.second;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        for(int i = 0; i<4; i++)
        {
            int nrow = x + dx[i];
            int ncol = y + dy[i];
            if(isValid(nrow,ncol,n,n) && grid[nrow][ncol]<=time)
                ds.unionBySize(nrow*n + ncol,x*n + y);
        }
        time++;
    }
    return time-1;
}
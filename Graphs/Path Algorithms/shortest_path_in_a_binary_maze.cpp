#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1,0,1,0};
vector<int> dcol = {0,1,0,-1};

int shortestPathBinaryMatrix(vector<vector<int>>&matrix, pair<int,int> source, pair<int,int>destination)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    vis[source.first][source.second] = 1;
    if (matrix[source.first][source.second]==0) return -1;
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{source.first,source.second}});
    int destRow = destination.first;
    int destCol = destination.second;
    while (!q.empty())
    {
        int dist = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        if (r==destRow && c==destCol) return dist;

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if ((nrow>=0 && nrow < n) && (ncol>=0 && ncol < m) && !vis[nrow][ncol] && matrix[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({dist+1,{nrow,ncol}});
            }
        }
    }
    return -1;
}

int shortestPathBinaryMatrixDijkstras(vector<vector<int>>&matrix, pair<int,int> source, pair<int,int>destination)
{
    int n = matrix.size();
    int m = matrix[0].size();
    queue<pair<int,pair<int,int>>>q;
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    q.push({0,{source.first,source.second}});
    if (matrix[source.first][source.second]==0) return -1;
    int destRow = destination.first;
    int destCol = destination.second;
    dist[source.first][source.second] = 0;
    while (!q.empty())
    {
        int steps = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        if (r==destRow && c==destCol) return steps;

        for (int i = 0;i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if ((nrow>=0 && nrow < n) && (ncol>=0 && ncol < m) && steps+1<dist[nrow][ncol] && matrix[nrow][ncol])
            {
                dist[nrow][ncol] = 1 + steps;
                q.push({steps+1,{nrow,ncol}});
            }
        }
    }
    return -1;
}
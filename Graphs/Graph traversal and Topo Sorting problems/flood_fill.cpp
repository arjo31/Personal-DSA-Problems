#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int sr,int sc, int color, int &initColor)
{
    queue<pair<int,int>>q;
    vis[sr][sc] = 1;
    grid[sr][sc] = color;
    q.push({sr,sc});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        for (int i = 0 ; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if ((nrow < grid.size() && nrow>=0) && (ncol < grid[0].size() && ncol>=0) && grid[nrow][ncol]==initColor && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                grid[nrow][ncol] = color;
                q.push({nrow,ncol});
            }
        }
    }
}

vector<vector<int>>floodFill(vector<vector<int>>&grid, int sr, int sc, int color)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    int initColor = grid[sr][sc];
    bfs(grid,vis,sr,sc,color,initColor);
    return grid;
}

int main()
{
    vector<vector<int>> grid = {
        {7,1,1,1},
        {1,7,7,7},
        {7,7,7,0},
        {7,7,7,4},
        {4,4,4,4}
    };
    floodFill(grid,2,2,5);
    for (int i = 0; i<grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
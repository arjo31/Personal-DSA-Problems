#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1 ,0};
vector<int> dcol = {0, 1, 0 , -1};

void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&vis)
{
    vis[row][col] = 1;
    for (int i = 0; i < 4 ; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if ((nrow >=0 && nrow < grid.size()) && (ncol>=0 && ncol < grid[0].size()) && !vis[nrow][ncol] && grid[nrow][ncol]==1)
        {
            dfs(nrow,ncol,grid,vis);
        }
    }
}

int numEnclaves(vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>vis(n, vector<int>(m,0));

    for(int i = 0 ; i < n ; i++)
    {
        if (!vis[i][0] && grid[i][0]==1)
        {
            dfs(i,0,grid,vis);
        }

        if (!vis[i][m-1] && grid[i][m-1]==1)
        {
            dfs(i,m-1,grid,vis);
        }
    }
    for(int j = 0 ; j < m ; j++)
    {
        if (!vis[0][j] && grid[0][j]==1)
        {
            dfs(0,j,grid,vis);
        }

        if (!vis[n-1][j] && grid[n-1][j]==1)
        {
            dfs(n-1,j,grid,vis);
        }
    }

    int count = 0;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            if (!vis[i][j] && grid[i][j]==1)
            {
                count++;
            }
        }
    }
    return count;
}
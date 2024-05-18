#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1,0,1,0};
vector<int> dcol = {0,1,0,-1};

void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&vis, vector<pair<int,int>>&vec, int base_row, int base_col)
{
    vis[row][col] = 1;
    vec.push_back({row - base_row, col - base_col});

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if ((nrow>=0 && nrow < grid.size()) && (ncol>=0 && ncol < grid[0].size()) && !vis[nrow][ncol] && grid[nrow][ncol]==1)
        {
            dfs(nrow,ncol,vis,grid,vec,base_row,base_col);
        }
    }
}

int countDistinctIslands(vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis (n,vector<int>(m,0));
    set <vector<pair<int,int>>> st;
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m ; j++)
        {
            if (!vis[i][j] && grid[i][j]==1)
            {
                vector<pair<int,int>> vec;
                dfs(i,j,grid,vis,vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}
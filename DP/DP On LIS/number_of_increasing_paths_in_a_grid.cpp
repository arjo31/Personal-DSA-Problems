/*You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.*/

#include <bits/stdc++.h>
using namespace std;

    vector<int>drow = {-1,0,1,0};
    vector<int>dcol = {0,1,0,-1};
    bool isValid(int row, int n, int col, int m)
    {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    const int MOD = 1e9 + 7;

        int solve(vector<vector<int>>&grid, int r, int c, vector<vector<int>>&dp)
    {
        if (dp[r][c]) return dp[r][c];
        dp[r][c] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;
            if (isValid(nrow, grid.size(), ncol, grid[0].size()) && grid[nrow][ncol] > grid[r][c])
            {
                dp[r][c] = (dp[r][c] + solve(grid, nrow, ncol, dp))%MOD;
            }
        }
        return dp[r][c];
    }

    int countPaths(vector<vector<int>>& grid)
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                count = (count+solve(grid, i, j, dp))%MOD;
            }
        }
        return count;
    }
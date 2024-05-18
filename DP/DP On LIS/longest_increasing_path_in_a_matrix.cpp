/*Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

bool isValid(int row, int n, int col, int m)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

int solve(vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &dp)
{
    if (dp[r][c])
        return dp[r][c];
    dp[r][c] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nrow = r + drow[i];
        int ncol = c + dcol[i];

        if (isValid(nrow, matrix.size(), ncol, matrix[0].size()) && matrix[nrow][ncol] > matrix[r][c])
        {
            dp[r][c] = max(dp[r][c], 1 + solve(matrix, nrow, ncol, dp));
        }
    }
    return dp[r][c];
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxPathSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maxPathSize = max(maxPathSize, solve(matrix, i, j, dp));
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return maxPathSize;
}
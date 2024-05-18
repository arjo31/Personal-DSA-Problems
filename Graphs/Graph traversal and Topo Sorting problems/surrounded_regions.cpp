/*Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

bool isValid(int r, int n, int c, int m)
{
    return (r >= 0 && r < n) && (c >= 0 && c < m);
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
        {
            q.push({i, 0});
            vis[i][0] = 1;
        }
        if (board[i][m - 1] == 'O')
        {
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (board[0][j] == 'O')
        {
            q.push({0, j});
            vis[0][j] = 1;
        }
        if (board[n - 1][j] == 'O')
        {
            q.push({n - 1, j});
            vis[n - 1][j] = 1;
        }
    }
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if (isValid(nrow, n, ncol, m) && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}
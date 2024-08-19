/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};
int n, m;
int minTime = 0;
bool isValid(int row, int col)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

void bfs(queue<pair<pair<int, int>, int>> &q, vector<vector<int>> &grid)
{
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        minTime = max(minTime, t);
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (isValid(nrow, ncol) && grid[nrow][ncol] == 1 && grid[nrow][ncol] != 2)
            {
                grid[nrow][ncol] = 2;
                q.push({{nrow, ncol}, t + 1});
            }
        }
    }
}
int orangesRotting(vector<vector<int>> &grid)
{
    n = grid.size();
    m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
                q.push({{i, j}, 0});
        }
    }
    bfs(q, grid);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                return -1;
    }
    return minTime;
}
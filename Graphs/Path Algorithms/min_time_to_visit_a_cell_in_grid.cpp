/*You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].

You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.

Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, int m)
{
    return ((row >= 0 && row < n) && (col >= 0 && col < m));
}

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

int minimumTime(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[0][0] = 1;
    p.push({0, {0, 0}});
    if (grid[0][1] <= 1)
    {
        p.push({1, {0, 1}});
        vis[0][1] = 1;
    }
    if (grid[1][0] <= 1)
    {
        p.push({1, {1, 0}});
        vis[1][0] = 1;
    }
    if (p.size() == 1)
        return -1;
    int ans = INT_MAX;
    while (!p.empty())
    {
        int time = p.top().first;
        int row = p.top().second.first;
        int col = p.top().second.second;
        p.pop();

        if (row == n - 1 && col == m - 1)
        {
            ans = min(ans, time);
        }

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (isValid(nrow, ncol, n, m) && !vis[nrow][ncol])
            {
                if (time + 1 >= grid[nrow][ncol])
                {
                    p.push({time + 1, {nrow, ncol}});
                }
                else
                {
                    int diff = grid[nrow][ncol] - time;
                    if (diff % 2 == 0)
                    {
                        p.push({grid[nrow][ncol] + 1, {nrow, ncol}});
                    }
                    else
                    {
                        p.push({grid[nrow][ncol], {nrow, ncol}});
                    }
                }
                vis[nrow][ncol] = 1;
            }
        }
    }
    return ans;
}
/*You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:

Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, -1, 0, 1};
int n;
int m;

bool isPossible(int row, int col) { return (row >= 0 && row < n && col >= 0 && col < m); }

int maxFish(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    queue<pair<int, int>> q;
    vis[row][col] = 1;
    q.push({row, col});
    int fish = 0;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        fish += grid[r][c];

        for (int i = 0; i < 4; i++)
        {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;
            if (isPossible(nrow, ncol) && !vis[nrow][ncol] && grid[nrow][ncol])
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    return fish;
}
int findMaxFish(vector<vector<int>> &grid)
{
    n = grid.size();
    m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int maxFishTaken = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] > 0)
                maxFishTaken = max(maxFishTaken, maxFish(i, j, grid, vis));
        }
    }
    return maxFishTaken;
}
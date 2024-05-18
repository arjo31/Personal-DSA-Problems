/*You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

bool isValid(int row, int n, int col, int m)
{
    return (row >= 0 && row < n) && (col >= 0 && col < m);
}

int maxAreaByBFS(int row, int n, int col, int m, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    queue<pair<int, int>> q;
    int area = 0;
    q.push({row, col});
    vis[row][col] = 1;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        area++;
        for (int i = 0; i < 4; i++)
        {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;
            if (isValid(nrow, n, ncol, m) && !vis[nrow][ncol] && grid[nrow][ncol])
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] && !vis[i][j])
            {
                int currArea = maxAreaByBFS(i, n, j, m, grid, vis);
                maxArea = max(maxArea, currArea);
            }
        }
    }
    return maxArea;
}
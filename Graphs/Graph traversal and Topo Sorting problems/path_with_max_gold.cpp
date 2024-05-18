/*In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.*/

#include <bits/stdc++.h>
using namespace std;

int maxGold = 0;
int tempMaxGold = 0;
int n, m;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

bool isValid(int row, int n, int col, int m)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

void dfs(vector<vector<int>> &grid, int row, int col)
{
    tempMaxGold += grid[row][col];
    maxGold = max(maxGold, tempMaxGold);
    int temp = grid[row][col];
    grid[row][col] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nrow = drow[i] + row;
        int ncol = dcol[i] + col;
        if (isValid(nrow, n, ncol, m) && grid[nrow][ncol] != 0)
        {
            dfs(grid, nrow, ncol);
        }
    }
    grid[row][col] = temp;
    tempMaxGold -= temp;
}

int getMaximumGold(vector<vector<int>>& grid)
{
    n = grid.size();
    m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j]!=0) dfs(grid,i,j);
        }
    }
    return maxGold;
}
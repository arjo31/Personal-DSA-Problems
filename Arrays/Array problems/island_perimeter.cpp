/*You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.*/

#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size();
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                ans += 4;
                // Check if there is a land cell to the left of the current cell
                if (i > 0 && grid[i - 1][j] == 1)
                    ans -= 2;
                // Check if there is a land cell above the current cell
                if (j > 0 && grid[i][j - 1] == 1)
                    ans -= 2;
            }
        }
    }
    return ans;
}
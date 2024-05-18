/*You are given a 2D matrix grid of size m x n. You need to check if each cell grid[i][j] is:

Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
Return true if all the cells satisfy these conditions, otherwise, return false.*/

#include <bits/stdc++.h>
using namespace std;

bool satisfiesConditions(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (m == 1)
    {
        for (int i = 0; i < n - 1; i++)
            if (grid[i][0] != grid[i + 1][0])
                return false;
        return true;
    }
    if (n == 1)
    {
        for (int i = 0; i < m - 1; i++)
            if (grid[0][i] == grid[0][i + 1])
                return false;
        return true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (grid[i][j] != grid[i + 1][j] || grid[i][j] == grid[i][j + 1])
            {
                return false;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
        if (grid[i][m - 1] != grid[i + 1][m - 1])
            return false;
    for (int i = 0; i < m - 1; i++)
        if (grid[n - 1][i] == grid[n - 1][i + 1])
            return false;
    return true;
}
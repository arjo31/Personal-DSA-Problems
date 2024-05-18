/*You are given a 2D matrix grid of size 3 x 3 consisting only of characters 'B' and 'W'. Character 'W' represents the white color, and character 'B' represents the black color.

Your task is to change the color of at most one cell so that the matrix has a 2 x 2 square where all cells are of the same color.

Return true if it is possible to create a 2 x 2 square of the same color, otherwise, return false.*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force
bool canMakeSquare(vector<vector<char>> &grid)
{
    char ch = grid[1][1];
    int W = 0, B = 0;
    ch == 'W' ? W++ : B++;
    // first box
    (grid[0][0] == 'W' ? W++ : B++);
    (grid[0][1] == 'W' ? W++ : B++);
    (grid[1][0] == 'W' ? W++ : B++);
    if (W > 2 || B > 2)
        return 1;
    W = 0, B = 0;
    ch == 'W' ? W++ : B++;

    // second box
    (grid[0][1] == 'W' ? W++ : B++);
    (grid[0][2] == 'W' ? W++ : B++);
    (grid[1][2] == 'W' ? W++ : B++);
    if (W > 2 || B > 2)
        return 1;
    W = 0, B = 0;
    ch == 'W' ? W++ : B++;

    // third box
    (grid[1][0] == 'W' ? W++ : B++);
    (grid[2][0] == 'W' ? W++ : B++);
    (grid[2][1] == 'W' ? W++ : B++);
    if (W > 2 || B > 2)
        return 1;
    W = 0, B = 0;
    ch == 'W' ? W++ : B++;

    // fourth box
    (grid[1][2] == 'W' ? W++ : B++);
    (grid[2][1] == 'W' ? W++ : B++);
    (grid[2][2] == 'W' ? W++ : B++);
    if (W > 2 || B > 2)
        return 1;

    return 0;
}

// General Method (For n x n matrices)
bool isPossible(vector<vector<char>> &grid, int i, int j)
{
    int W = 0, B = 0;
    for (int x = i; x < i + 2; x++)
    {
        for (int y = j; y < j + 2; y++)
        {
            if (grid[x][y] == 'W')
                W++;
            else
                B++;
        }
    }
    if (W > 2 || B > 2)
        return 1;
    return 0;
}

bool canMakeSquare(vector<vector<char>> &grid)
{
    int n = grid.size();
    for (int i = 0; i <= n - 2; i++)
    { // n- 2 since square size is 2
        for (int j = 0; j <= n - 2; j++)
        {
            if (isPossible(grid, i, j))
                return 1;
        }
    }
    return 0;
}
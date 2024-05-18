/*You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).*/

#include <bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    auto flipRow = [&](int row)
    {
        for (int i = 0; i < m; i++)
            grid[row][i] = !grid[row][i];
    };

    auto flipCol = [&](int col)
    {
        for (int i = 0; i < n; i++)
            grid[i][col] = !grid[i][col];
    };

    auto convertRowBinToDec = [&](const vector<int> &arr)
    {
        int res = 0;
        for (int num : arr)
        {
            res = res * 2 + num;
        }
        return res;
    };

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 0)
            flipRow(i);
    }

    for (int j = 1; j < m; j++)
    {
        int countOne = 0;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == 1)
                countOne++;
        }
        if (countOne * 2 < n)
            flipCol(j);
    }

    int ans = 0;
    for (const auto row : grid)
    {
        ans += convertRowBinToDec(row);
    }
    return ans;
}
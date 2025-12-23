/*You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.

You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:

Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all row1i <= x <= row2i and col1i <= y <= col2i.
Return the matrix mat after performing every query.*/

// Basically it is a difference array technique for 2D matrix.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
{
    vector<vector<int>> mat(n, vector<int>(n, 0));

    for (auto query : queries)
    {
        int r1 = query[0];
        int c1 = query[1];
        int r2 = query[2];
        int c2 = query[3];

        for (int row = r1; row <= r2; row++)
        {
            mat[row][c1] += 1;
            if (c2 + 1 < n)
                mat[row][c2 + 1] -= 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            mat[i][j] += mat[i][j - 1];
        }
    }
    return mat;
}
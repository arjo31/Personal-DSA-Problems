/*Determine if a 9 x 9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules :

    Each row must contain the digits 1 -
    9 without repetition.Each column must contain the digits 1 - 9 without repetition.Each of the nine 3 x 3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.Note :

    A Sudoku
    board(partially filled) could be valid but is not necessarily solvable.Only the filled cells need to be validated according to the mentioned rules.*/

#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    const int num = 9;
    bool row[num][num] = {false};
    bool col[num][num] = {false};
    bool subGrid[num][num] = {false};

    for (int r = 0; r < num; ++r)
    {
        for (int c = 0; c < num; ++c)
        {
            if (board[r][c] == '.')
                continue;

            int idx = board[r][c] - '0' - 1; // char to num idx
            int gridNum = (r / 3) * 3 + (c / 3);

            if (row[r][idx] || col[c][idx] || subGrid[gridNum][idx])
            {
                return false; // if duplicate number found, the Sudoku board is invalid
            }
            row[r][idx] = true;
            col[c][idx] = true;
            subGrid[gridNum][idx] = true;
        }
    }
    return true;
}
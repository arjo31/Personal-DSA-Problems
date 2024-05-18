/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

bool isValid(int row, int n, int col, int m)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

bool dfs(vector<vector<char>> &board, string word, vector<vector<int>> &vis, int n, int m, int row, int col, int ind)
{
    vis[row][col] = 1;

    if (ind == word.size() - 1)
        return true;

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (isValid(nrow, n, ncol, m) && !vis[nrow][ncol] && board[nrow][ncol] == word[ind + 1])
        {
            if (dfs(board, word, vis, n, m, nrow, ncol, ind + 1))
                return true;
        }
    }

    vis[row][col] = 0;
    return false;
}
    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int ind = 0;
        int wordSize = word.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j]==word[0]) {
                    if (dfs(board, word,vis, n, m, i, j,0)) return true;
                }
            }
        }
        return false;

    }
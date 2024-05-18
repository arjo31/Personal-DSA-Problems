/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.*/

#include <bits/stdc++.h>
using namespace std;

// Have to apply BFS. Whenever they ask of a minimum and have to go step by step.. go for BFS

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
            {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;
        q.pop();

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if ((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) && !vis[nrow][ncol])
            {
                q.push({{nrow, ncol}, step + 1});
                vis[nrow][ncol] = 1;
            }
        }
        dist[row][col] = step;
    }
    return dist;
}
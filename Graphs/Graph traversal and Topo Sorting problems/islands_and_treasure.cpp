/*You are given a 𝑚×𝑛 2D grid initialized with these three possible values:

-1 - A water cell that can not be traversed.
0 - A treasure chest.
INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.
Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest than the value should remain INF.

Assume the grid can only be traversed up, down, left, or right.*/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
vector<int> drow = {0, 1, 0, -1};
vector<int> dcol = {-1, 0, 1, 0};

bool isValid(int row, int n, int col, int m)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

void islandsAndTreasure(vector<vector<int>> &grid)
{
    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
                q.push({0, {i, j}});
        }
    }
    while (!q.empty())
    {
        int step = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;
            if (isValid(nrow, n, ncol, m) && grid[nrow][ncol] == INF)
            {
                grid[nrow][ncol] = step + 1;
                q.push({step + 1, {nrow, ncol}});
            }
        }
    }
}
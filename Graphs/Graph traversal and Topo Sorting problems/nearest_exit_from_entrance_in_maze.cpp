/*You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.*/

#include <bits/stdc++.h>
using namespace std;

int srcRow, srcCol, n, m;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

bool isValid(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}

bool isBoundary(int r, int c)
{
    return (r == n - 1 || c == m - 1 || r == 0 || c == 0);
}

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    srcRow = entrance[0];
    srcCol = entrance[1];
    if (maze[srcRow][srcCol] == '+')
        return -1;
    n = maze.size();
    m = maze[0].size();
    queue<pair<pair<int, int>, int>> q;
    q.push({{srcRow, srcCol}, 0});
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[srcRow][srcCol] = 1;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        if (isBoundary(r, c))
        {
            if (r == srcRow && c == srcCol)
            {
            }
            else
                return steps;
        }

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (isValid(nrow, ncol) && !vis[nrow][ncol] && maze[nrow][ncol] == '.')
            {
                q.push({{nrow, ncol}, steps + 1});
                vis[nrow][ncol] = 1;
            }
        }
    }
    return -1;
}
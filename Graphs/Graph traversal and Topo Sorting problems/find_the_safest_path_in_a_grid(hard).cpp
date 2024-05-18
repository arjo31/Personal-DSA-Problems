/*You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};
int n;
int maxSafenessFactor = INT_MIN;
int minTempSafeness = INT_MAX;

bool isValid(int row, int col)
{
    return (row >= 0 && row < n && col >= 0 && col < n);
}

// Brute Force
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid)
{
    int temp = minTempSafeness;
    minTempSafeness = min(minTempSafeness, grid[row][col]);
    if (row == n - 1 && col == n - 1)
    {
        maxSafenessFactor = max(maxSafenessFactor, minTempSafeness);
        minTempSafeness = temp;
        return;
    }
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nrow = drow[i] + row;
        int ncol = dcol[i] + col;
        if (isValid(nrow, ncol) && !vis[nrow][ncol])
            dfs(nrow, ncol, vis, grid);
    }
    vis[row][col] = 0;
    minTempSafeness = temp;
}

int maximumSafenessFactor(vector<vector<int>> &grid)
{
    n = grid.size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> vis(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                vis[i][j] = 0;
                q.push({0, {i, j}});
            }
        }
    }
    while (!q.empty())
    {
        int steps = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (isValid(nrow, ncol) && vis[nrow][ncol] == -1)
            {
                vis[nrow][ncol] = steps + 1;
                q.push({steps + 1, {nrow, ncol}});
            }
        }
    }
    grid = vis;
    for (int i = 0; i < n; i++)
        vis[i].assign(n, 0);
    dfs(0, 0, vis, grid);
    return maxSafenessFactor;
}

// O(n^2logn) - using Binary Search
bool isSafe(vector<vector<int>> &grid, int safeFactor)
{
    int n = grid.size();
    queue<pair<int, int>> q;
    if (grid[0][0] < safeFactor)
        return false;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[0][0] = 1;
    q.push({0, 0});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == n - 1 && c == n - 1)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;
            if (isValid(nrow, ncol) && grid[nrow][ncol] >= safeFactor && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
    return false;
}

int maximumSafenessFactor(vector<vector<int>> &grid)
{
    n = grid.size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> vis(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                vis[i][j] = 0;
                q.push({0, {i, j}});
            }
        }
    }
    while (!q.empty())
    {
        int steps = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (isValid(nrow, ncol) && vis[nrow][ncol] == -1)
            {
                vis[nrow][ncol] = steps + 1;
                q.push({steps + 1, {nrow, ncol}});
            }
        }
    }
    grid = vis;
    vis.clear();
    for (int i = 0; i < n; i++)
        maxSafenessFactor = max(maxSafenessFactor, *max_element(grid[i].begin(), grid[i].end()));
    int low = 0;
    int high = maxSafenessFactor;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isSafe(grid, mid))
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

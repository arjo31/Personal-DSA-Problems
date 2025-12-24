#include <bits/stdc++.h>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

// Memoization
int solveMemoize(int row, int col, vector<vector<int>> &grid, unordered_map<pair<int, int>, int, pair_hash> &mpp)
{
    pair<int, int> key = {row, col};
    if (mpp.find(key) != mpp.end())
    {
        return mpp[key];
    }
    if (row < 0 || col < 0)
        return mpp[key] = 1e9;
    if (row == 0 && col == 0)
        return mpp[key] = grid[row][col];
    int leftPath = solveMemoize(row, col - 1, grid, mpp) + grid[row][col];
    int upPath = solveMemoize(row - 1, col, grid, mpp) + grid[row][col];
    return mpp[key] = min(leftPath, upPath);
}

int minPathSumMemoization(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    unordered_map<pair<int, int>, int, pair_hash> mpp;
    return solveMemoize(row - 1, col - 1, grid, mpp);
}

// Tabulation
int minPathSumTabulation(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < col; j++)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            int rightPath = dp[i][j - 1] + grid[i][j];
            int downPath = dp[i - 1][j] + grid[i][j];
            dp[i][j] = min(rightPath, downPath);
        }
    }
    return dp[row - 1][col - 1];
}

// Djikstra's Algo
class Djikstra
{
private:
    vector<int> drow = {0, 1};
    vector<int> dcol = {1, 0};

    bool isValid(int row, int col, int n, int m)
    {
        return ((row >= 0 && row < n) && (col >= 0 && col < m));
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = grid[0][0];
        p.push({grid[0][0], {0, 0}});
        while (!p.empty())
        {
            int d = p.top().first;
            int r = p.top().second.first;
            int c = p.top().second.second;
            p.pop();

            for (int i = 0; i < 2; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (isValid(nrow, ncol, n, m))
                {
                    int step = d + grid[nrow][ncol];
                    if (step < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = step;
                        p.push({step, {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
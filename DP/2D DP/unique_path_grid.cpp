/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.*/

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
int solveMemoize(int row, int col, unordered_map<pair<int, int>, int, pair_hash> &mpp)
{
    pair<int, int> key = {row, col};
    if (mpp.find(key) != mpp.end())
    {
        return mpp[key];
    }
    if (row == 0 && col == 0)
    {
        return mpp[key] = 1;
    }
    if (row < 0 || col < 0)
    {
        return 0;
    }
    int firstPath = solveMemoize(row, col - 1, mpp);
    int secondPath = solveMemoize(row - 1, col, mpp);

    return mpp[key] = firstPath + secondPath;
}

int uniquePathsMemoization(int row, int col)
{
    unordered_map<pair<int, int>, int, pair_hash> mpp;
    return solveMemoize(row - 1, col - 1, mpp);
}

// Tabulation
int uniquePathsTabulation(int row, int col)
{
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = 1;
    for (int i = 1; i < col; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < row; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[row - 1][col - 1];
}
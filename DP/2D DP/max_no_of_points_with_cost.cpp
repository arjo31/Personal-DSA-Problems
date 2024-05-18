/*You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
long long solveMemoization(vector<vector<int>> &points, int r, int c, int n, int m, vector<vector<int>> &dp)
{
    if (r == n - 1)
    {
        return dp[r][c] = points[r][c];
    }
    if (dp[r][c] != -1)
        return dp[r][c];
    long long maxPoints = LONG_MIN;
    for (int i = 0; i < m; i++)
    {
        maxPoints = max(maxPoints, points[r][c] + solveMemoization(points, r + 1, i, n, m, dp) - abs(c - i));
    }
    return dp[r][c] = maxPoints;
}

long long maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int m = points[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    long long ans = LONG_MIN;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, solveMemoization(points, 0, i, n, m, dp));
    }
    return ans;
}

// Tabulation
long long maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int m = points[0].size();
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    for (int i = 0; i < m; i++)
        dp[n - 1][i] = points[n - 1][i];
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            long long maxPoints = 0;
            for (int k = 0; k < m; k++)
            {
                if (maxPoints < points[i][j] + dp[i + 1][k] - abs(j - k))
                    maxPoints = points[i][j] + dp[i + 1][k] - abs(j - k);
            }
            dp[i][j] = maxPoints;
        }
    }
    long long ans = 0;
    for (int col = 0; col < m; col++)
    {
        if (ans < dp[0][col])
            ans = dp[0][col];
    }
    return ans;
}

// O(n^2) tabulation
long long solve(vector<vector<int>> &points)
{
    int n = points.size();
    int m = points[0].size();
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    for (int i = 0; i < m; i++)
        dp[n - 1][i] = points[n - 1][i];
    for (int i = n - 2; i >= 0; i--)
    {
        vector<long long> left(m, -1);
        vector<long long> right(m, -1);
        left[0] = dp[i + 1][0];
        for (int k = 1; k < m; k++)
        {
            left[k] = max(left[k - 1], dp[i + 1][k] + k);
        }

        right.back() = dp[i + 1].back() - points[i].size() + 1;
        for (int k = m - 2; k >= 0; k--)
        {
            right[k] = max(right[k + 1], dp[i + 1][k] - k);
        }

        for (int j = 0; j < m; j++)
        {
            dp[i][j] = max(left[j] - j, right[j] + j) + points[i][j];
        }
    }
    long long ans = 0;
    for (int col = 0; col < m; col++)
    {
        if (ans < dp[0][col])
            ans = dp[0][col];
    }
    return ans;
}
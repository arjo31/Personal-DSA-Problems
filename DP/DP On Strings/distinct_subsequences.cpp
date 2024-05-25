/*Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solveMemoization(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = solveMemoization(i - 1, j - 1, s1, s2, dp) + solveMemoization(i - 1, j, s1, s2, dp);
    return dp[i][j] = solveMemoization(i - 1, j, s1, s2, dp);
}

int distinctSubsequences(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solveMemoization(n - 1, m - 1, s1, s2, dp);
}

// Tabulation
int distinctSubsequences(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // Base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}
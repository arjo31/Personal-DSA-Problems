/*Given two strings. The task is to find the length of the longest common substring.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization - TLE
int ans = 0;
int solve(int i, int j, int n, int m, string s1, string s2, vector<vector<int>> &dp)
{
    if (i == n || j == m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        dp[i][j] = 1 + solve(i + 1, j + 1, n, m, s1, s2, dp);
        ans = max(ans, dp[i][j]);
    }
    else
        dp[i][j] = 0;
    solve(i + 1, j, n, m, s1, s2, dp);
    solve(i, j + 1, n, m, s1, s2, dp);
    return dp[i][j];
}

int lcsTabulation(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}
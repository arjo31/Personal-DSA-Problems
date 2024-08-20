/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m
substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.*/

#include <bits/stdc++.h>
using namespace std;

int n, m;

// Memoization
bool solve(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>> &dp)
{
    if (i == n && j == m && k == (n + m))
        return true;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s3[k] && s2[j] == s3[k])
    {
        dp[i][j] = solve(i + 1, j, k + 1, s1, s2, s3, dp) || solve(i, j + 1, k + 1, s1, s2, s3, dp);
    }
    else if (s1[i] == s3[k])
        dp[i][j] = solve(i + 1, j, k + 1, s1, s2, s3, dp);
    else if (s2[j] == s3[k])
        dp[i][j] = solve(i, j + 1, k + 1, s1, s2, s3, dp);
    else
        dp[i][j] = false;
    return dp[i][j];
}

bool isInterleave(string s1, string s2, string s3)
{
    n = s1.size();
    m = s2.size();
    if ((n + m) != s3.size())
        return false;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(0, 0, 0, s1, s2, s3, dp);
}

// Tabulation
bool isInterleave(string s1, string s2, string s3)
{
    n = s1.size();
    m = s2.size();
    if (n + m != s3.size())
        return false;
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i > 0 && s1[i - 1] == s3[i + j - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
            if (j > 0 && s2[j - 1] == s3[i + j - 1])
            {
                dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
    }

    return dp[n][m];
}

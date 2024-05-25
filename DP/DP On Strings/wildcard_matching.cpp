/*Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
bool solveMemoization(int i, int j, string pattern, string text, vector<vector<int>> dp)
{
    if (j < 0 && i < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int t = 0; t <= i; t++)
        {
            if (pattern[t] != '*')
                return false;
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return dp[i][j] = solveMemoization(i - 1, j - 1, pattern, text, dp);
    }
    if (pattern[i] == '*')
    {
        return dp[i][j] = solveMemoization(i - 1, j, pattern, text, dp) || solveMemoization(i, j - 1, pattern, text, dp);
    }
    return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solveMemoization(n - 1, m - 1, pattern, text, dp);
}

// Tabulation
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, -1));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int t = 1; t <= i; t++)
        {
            if (pattern[t - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
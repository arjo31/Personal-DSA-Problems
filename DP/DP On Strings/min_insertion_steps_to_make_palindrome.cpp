/*Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.*/

/*Same for minimum deletions to make string palindrome*/

#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequenceTabulation(string s)
{
    int n = s.length();
    string rev = string(s.rbegin(), s.rend()); // Reverse a string
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == rev[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int minInsertions(string s)
{
    int x = longestPalindromicSubsequenceTabulation(s);
    return s.size() - x;
}
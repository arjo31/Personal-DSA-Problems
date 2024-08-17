/*Given a string, print the longest repeating subsequence such that the two subsequence don't have same string character at same position, i.e., any i'th character in the two subsequences shouldn't have the same index in the original string.*/

#include <bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string str)
{
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][n] = 0;
    for (int j = 0; j <= n; j++)
        dp[n][j] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (str[i] == str[j] && i != j)
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}

// Print longest repeating subsequence
string printLongestRepeatingSubsequence(string str)
{
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][n] = 0;
    for (int j = 0; j <= n; j++)
        dp[n][j] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (str[i] == str[j] && i != j)
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    int i = 0;
    int j = 0;

    string ans = "";

    while (i != n && j != n)
    {
        if (str[i] == str[j] && i != j)
        {
            ans += str[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
            i++;
        else
            j++;
    }

    return ans;
}
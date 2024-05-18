/*You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int prev, int ind, string s, int k, vector<vector<int>> &dp)
{
    if (ind == s.size())
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];

    int pick = INT_MIN;
    if (prev == -1 || (prev != -1 && abs(s[prev] - s[ind]) <= k))
        pick = 1 + solve(ind, ind + 1, s, k, dp);
    int notPick = solve(prev, ind + 1, s, k, dp);
    return dp[ind][prev + 1] = max(pick, notPick);
}

int longestIdealString(string s, int k)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    solve(-1, 0, s, k, dp);
    return dp[0][-1 + 1];
}

// Tabulation
int longestIdealString(string s, int k)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int prev = n - 1; prev >= 0; --prev)
    {
        for (int ind = n - 1; ind >= 0; --ind)
        {
            int pick = 0;
            if (prev == n || abs(s[prev] - s[ind]) <= k)
                pick = 1 + dp[ind][ind + 1];
            int notPick = dp[prev + 1][ind + 1];
            dp[prev][ind] = max(pick, notPick);
        }
    }

    return dp[0][0];
}

// Space optimization
int longestIdealString(string s, int k)
{
    int dp[27] = {0};
    int n = s.length();

    for (int i = n - 1; i >= 0; i--)
    {
        char cc = s[i];
        int idx = cc - 'a';
        int maxi = -__INT_MAX__;

        int left = max((idx - k), 0);
        int right = min((idx + k), 26);

        for (int j = left; j <= right; j++)
        {
            maxi = max(maxi, dp[j]);
        }

        dp[idx] = maxi + 1;
    }

    int max = -__INT_MAX__;
    for (int i = 0; i < 27; i++)
    {
        if (dp[i] > max)
            max = dp[i];
    }

    return max;
}
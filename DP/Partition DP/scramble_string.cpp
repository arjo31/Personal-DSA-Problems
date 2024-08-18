/*We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.*/

#include <bits/stdc++.h>
using namespace std;

// TC : O(N^4) and SC : O(N^2)
unordered_map<string, int> mpp;
bool isScramble(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    if (s1 == "" && s2 == "")
        return true;
    int n = s1.length();
    vector<int> dp(n + 1, -1);
    return solve(s1, s2);
}

bool solve(string s1, string s2)
{
    if (s1 == s2)
        return true;
    if (s1.size() <= 1)
        return false;
    string key = s1 + " " + s2;
    if (mpp.find(key) != mpp.end())
        return mpp[key];

    int n = s1.size();
    bool flag = false;
    for (int k = 1; k < n; k++)
    {
        bool cond1 = (solve(s1.substr(0, k), s2.substr(n - k, k)) && solve(s1.substr(k, n - k), s2.substr(0, n - k))); // Swap
        bool cond2 = (solve(s1.substr(0, k), s2.substr(0, k)) && solve(s1.substr(k, n - k), s2.substr(k, n - k)));     // No Swap
        if (cond1 || cond2)
        {
            flag = true;
            break;
        }
    }
    return mpp[key] = flag;
}

// Tabulation
bool isScramble(string s1, string s2)
{
    int n = s1.length();
    if (n != s2.length())
        return false;
    if (s1 == s2)
        return true;

    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

    // Initialize the DP table for substrings of length 1
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dp[i][j][1] = (s1[i] == s2[j]);
        }
    }

    // Fill the DP table for substrings of length 2 to n
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            for (int j = 0; j <= n - len; ++j)
            {
                for (int k = 1; k < len; ++k)
                {
                    if ((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i][j + len - k][k] && dp[i + k][j][len - k]))
                    {
                        dp[i][j][len] = true;
                        break;
                    }
                }
            }
        }
    }

    return dp[0][0][n];
}
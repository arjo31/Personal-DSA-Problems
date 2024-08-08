/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

// Memoization
int solveMemoization(int i, int n, string &s, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int minCutCost = INT_MAX;

    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            int cost = 1 + solveMemoization(j + 1, n, s, dp);
            minCutCost = min(minCutCost, cost);
        }
    }
    return dp[i] = minCutCost;
}

int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return solveMemoization(0, n, s, dp) - 1; // To remove the case where partition is done at the end of the string.
}

// Tabulation
int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int minCutCost = INT_MAX;

        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + dp[j + 1];
                minCutCost = min(minCutCost, cost);
            }
        }
        dp[i] = minCutCost;
    }
    return dp[0] - 1;
}
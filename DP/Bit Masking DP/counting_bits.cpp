/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.*/

#include <bits/stdc++.h>
using namespace std;

// O(nlogn) using built in pop count
vector<int> countBits(int n)
{
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        ans.push_back(__builtin_popcount(i));
    }
    return ans;
}

// Using DP
vector<int> countBits(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i / 2] + i % 2;
    }
    return dp;
}
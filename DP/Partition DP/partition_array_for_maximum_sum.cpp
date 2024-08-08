/*Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.*/

#include <bits/stdc++.h>
using namespace std;

int n;
// Memoization
int solveMemoization(int i, vector<int> &arr, int k, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for (int j = i; j < min(i + k, n); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int cost = len * maxi + solveMemoization(j + 1, arr, k, dp);
        maxAns = max(maxAns, cost);
    }
    return dp[i] = maxAns;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    n = arr.size();
    vector<int> dp(n, -1);
    return solveMemoization(0, arr, k, dp);
}

// Tabulation
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = i; j < min(i + k, n); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int cost = len * maxi + dp[j + 1];
            maxAns = max(maxAns, cost);
        }
        dp[i] = maxAns;
    }
    return dp[0];
}
#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int s = 0; s <= sum; s++)
        {
            int notPick = dp[i + 1][s];
            int pick = 0;
            if (arr[i] <= s)
                pick = dp[i + 1][s - arr[i]];
            dp[i][s] = pick || notPick;
        }
    }
    vector<int> diff = dp[0];
    int minDiff = INT_MAX;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (diff[i])
            minDiff = min(minDiff, sum - 2 * i);
    }
    return minDiff;
}
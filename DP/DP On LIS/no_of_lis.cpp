/*Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.*/
/*count array is used : count[i] refers to the count of the longest increasing subsequences of the original array that are possible of length dp[i] with the element arr[i] as its last element*/

#include <bits/stdc++.h>
using namespace std;

int noOfLIS(vector<int>&arr)
{
    int n = arr.size();
    vector<int>dp(n,1), count(n,1);

    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i ; prev++)
        {
            if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i])
            {
                dp[i] = dp[prev] + 1;
                count[i] = count[prev];
            }
            else if (arr[prev] < arr[i] && dp[prev] + 1 == dp[i])
            {
                count[i] = count[i] + count[prev];
            }
        }
        maxi = max(maxi,dp[i]);
    }
    int noofLIS = 0;
    for (int i = 0 ;i < n ; i++)
    {
        if (dp[i]==maxi) noofLIS+=count[i];
    }
    return noofLIS;
}
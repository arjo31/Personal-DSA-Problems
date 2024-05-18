#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& nums, int n)
{
    int sum = accumulate(nums.begin(),nums.end(),0);
    vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
    for (int i = 0; i < n ; i++)
    {
        dp[i][0] = true;
    }    
    if (nums[0]<=sum)
    {
        dp[0][nums[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target<=sum; target++)
        {
            bool take = false;
            bool notake = dp[i-1][target];
            if (nums[i]<=target) take = dp[i-1][target - nums[i]];
            dp[i][target] = take || notake;
        }
    }
    int _min = 1e9;
    int s1 = 0, s2 = sum;
    for (int i = 0; i <= sum/2 ; i++)
    {
        if (dp[n-1][i])
        {
            s1 = i;
            s2 = sum-i;
            _min = min(_min,abs(s1-s2));
        }
    }
    return _min;
}
#include <bits/stdc++.h>
using namespace std;

//This considers the case when arr[i] includes the number 0

//Memoization
int solveMemoization(int n, int k, vector<int>&arr, vector<vector<int>>&dp)
{
    if (n==0)
    {
        if (k==0 && arr[0]==0) return 2;
        if (k==0 || k==arr[0]) return 1;
        return 0;
    }
    if (dp[n][k]!=-1) return dp[n][k];
    int notTake = solveMemoization(n-1,k,arr,dp);
    int take = 0;
    if (arr[n]<=k)
    {
        take = solveMemoization(n-1,k-arr[n],arr,dp);
    }
    dp[n][k] = notTake + take;
    return dp[n][k];
}

int countSubsetsMemoization(int n, int d, vector<int>&arr)
{
    int sum = accumulate(arr.begin(),arr.end(),0);
    if ((sum-d)%2!=0 || (sum-d)<0) return 0;
    int k = (sum - d)/2;
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    return solveMemoization(n-1,k,arr,dp);
}

//Tabulation
int countPartitionsTabulation(int n, int d, vector<int>&arr)
{
    int sum = accumulate(arr.begin(),arr.end(),0);
    if ((sum-d)%2!=0 || (sum-d)<0) return 0;
    int k = (sum - d)/2;
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    if (arr[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0]<=k && arr[0]!=0)
    {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for(int target = 0; target<=k; target++)
        {
            int take = 0;
            int notTake = dp[i-1][target];
            if (arr[i]<=target) take = dp[i-1][target - arr[i]];
            dp[i][target] = (notTake + take)%(int)(1e9+7);
        }
    }
    return dp[n-1][k];
}
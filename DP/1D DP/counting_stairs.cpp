#include <bits/stdc++.h>
using namespace std;

//Recursive
int climbingStairsRecursive(int n)
{
    if (n==0) return 1;
    if (n==1) return 1;
    return climbingStairsRecursive(n-2) + climbingStairsRecursive(n-1);
}

//Memoization
int climbStairs(int n, unordered_map<int,int>&mpp)
{
    if (mpp.find(n)!=mpp.end())
    {
        return mpp[n];
    }
    if (n==0)
    {
        return mpp[0] = 1;
    }
    if (n==1)
    {
        return mpp[1] = 1;
    }
    mpp[n] = climbStairs(n-1,mpp) + climbStairs(n-2,mpp);
    return mpp[n];
}

int climbingStairsMemoization(int n)
{
    unordered_map<int,int>mpp;
    return climbStairs(n,mpp);
}

//Tabulation
int climbStairs(int n, vector<int>&dp)
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i<=n ;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int climbingStairsTabulation(int n)
{
    vector<int>dp(n+1,-1);
    return climbStairs(n,dp);
}

//Space Optimization
int climbStairsSpaceOptimization(int n)
{
    int prev = 1;
    int curr = 1;
    int next;
    for (int i = 2; i<=n; i++)
    {
        next = curr+prev;
        prev = curr;
        curr = next;
    }
    return next;
}
#include <bits/stdc++.h>
using namespace std;

//Recursion
int frogJumpRecursion(int n,vector<int>heights)
{
    if (n<=0) return 0;
    return min(frogJumpRecursion(n-1,heights)+abs(heights[n] - heights[n-1]),frogJumpRecursion(n-2,heights) + abs(heights[n] - heights[n-2]));
}

//Memoization
int solveMemoization(int n, vector<int>&heights, unordered_map<int,int>&mpp)
{
    if (mpp.find(n)!=mpp.end())
    {
        return mpp[n];
    }
    if (n==0)
    {
        return mpp[n]=0;
    }
    int second = INT_MAX;
    int first = solveMemoization(n-1,heights,mpp) + abs(heights[n] - heights[n-1]);
    if (n>1)
    {
        second = solveMemoization(n-2,heights,mpp) + abs(heights[n] - heights[n-2]);
    }
    mpp[n] = min(first,second);
    return mpp[n];
}

int frogJumpMemoization(int n, vector<int>heights)
{
    unordered_map<int,int>mpp;
    return solveMemoization(n-1,heights,mpp);
}

//Tabulation
int solveTabulation(int n,vector<int>&heights, vector<int>&dp)
{
    dp[0] = 0;
    for (int i = 1; i<=n ;i++)
    {
        int second = INT_MAX;
        int first = dp[i-1] + abs(heights[i]-heights[i-1]);
        if (i>1)
        {
            second = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(first,second);
    }
    return dp[n];
}

int frogJumpTabulation(int n, vector<int>heights)
{
    vector<int>dp(n+1,0);
    return solveTabulation(n-1,heights,dp);
}

//Space optimization
int frogJumpSO(int n, vector<int>heights)
{
    int prev1 = 0;
    int prev2 = 0;
    int next;
    for (int i = 1; i<n; i++)
    {
        int second = INT_MAX;
        int first = prev1 + abs(heights[i] - heights[i-1]);
        if (i > 1)
        {
            second = prev2 + abs(heights[i] - heights[i-2]);
        }
        next = min(first,second);
        prev2 = prev1;
        prev1 = next;
    }
    return prev1;
}
#include <bits/stdc++.h>
using namespace std;

//Memoization
int solveMemoization(int n, vector<int>&height, unordered_map<int,int>&mpp, int k)
{
    if (n==0)
    {
        return mpp[n] = 0;
    }
    if (mpp.find(n)!=mpp.end())
    {
        return mpp[n];
    }
    int steps = INT_MAX;

    for (int j = 1; j<=k; j++)
    {
        if (n-j>=0)
        {
            int jump = solveMemoization(n-j,height,mpp,k) + abs(height[n] - height[n-j]);
            steps = min(steps,jump);
        }
    }
    return mpp[n] = steps;
}

int frogJumpKDistMemoization(int n, vector<int>&height, int k)
{
    unordered_map<int,int>mpp;
    return solveMemoization(n-1,height,mpp,k);
}

//Tabulation
int solveTabulation(int n, vector<int>&dp, vector<int>&height, int k)
{
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int steps = INT_MAX;

        for(int j = 1; j<=k; j++)
        {
            if(i-j>=0)
            {
                int jump = dp[i-j] + abs(height[i] - height[i-j]); 
                steps = min(steps,jump);
            }
        }
        dp[i] = steps;
    }
    return dp[n];
}

int frogJumpKDistTabulation(int n, vector<int>&height, int k)
{
    vector<int>dp(n+1,0);
    return solveTabulation(n-1,dp,height,k);
}
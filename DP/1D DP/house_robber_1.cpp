#include<bits/stdc++.h>
using namespace std;

/*

Money = [1,2,3,1]
indices=[0,1,2,3]

We pick f(3) -> can go to f(1) -> cannot go if index < 0
or
We pick f(2) -> can go to f(0) -> cannot go further than 0

f(0) returns money[0] base case:

need to find the maximum sum of money which u can take without alerting the police

*/

//Recursion
int solveRecursion(int index,vector<int>&money)
{
    if (index==0) return money[0];
    if (index<0) return 0;
    return max(solveRecursion(index-2,money) + money[index], solveRecursion(index-1,money));
}

int houseRobberRecursion(vector<int>&money)
{
    return solveRecursion(money.size()-1,money);
}

//Memoization
int solveMemoization(int index, vector<int>&money, unordered_map<int,int>&mpp)
{
    if (mpp.find(index)!=mpp.end())
    {
        return mpp[index];
    }
    if (index==0)
    {
        return mpp[index]=money[0];
    }
    if (index<0)
    {
        return mpp[index] = 0;
    }
    int pick = solveMemoization(index-2,money,mpp)+money[index];
    int notpick = solveMemoization(index - 1,money,mpp);
    return mpp[index] = max(pick,notpick);
}

int houseRobberMemoization(vector<int>&money)
{
    unordered_map<int,int>mpp;
    return solveMemoization(money.size()-1,money,mpp);
}

//Tabulation
int solveTabulation(int n,vector<int>&money, vector<int>&dp)
{
    dp[0] = money[0];
    for (int i = 1; i<n; i++)
    {
        int pick = money[i];
        if (i > 1)
        {
            pick = pick + money[i];
        }
        int notpick = dp[i-1] + 0;
        dp[i] = max(pick,notpick);
    }
    return dp[n-1];
}

int houseRobberTabulation(vector<int>&money)
{
    int n = money.size();
    vector<int>dp(n,0);
    return solveTabulation(n,money,dp);
}

//Space Optimmization
int houseRobberSO(vector<int>&money)
{
    int prev = money[0];
    int prev2 = 0;

    int n = money.size();
    for (int i = 1; i<n; i++)
    {
        int pick = money[i];
        if (i > 1)
        {
            pick+=prev2;
        }
        int notpick = prev;

        int cur_i = max(pick,notpick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}
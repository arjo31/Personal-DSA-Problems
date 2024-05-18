#include <bits/stdc++.h>
using namespace std;

//Insertion, Deletion and Replacement takes place

//Memoization
int solveMemoization(int i, int j, string s1, string s2, vector<vector<int>>&dp)
{
    if (i < 0) return j+1; //No more s1 ... to convert to s2 ... add characters
    if (j < 0) return i+1; //no more s2 ... to convert to s1 ... delete characters
    if (dp[i][j]!=-1) return dp[i][j];

    if (s1[i]==s2[j]) return 0+solveMemoization(i-1,j-1,s1,s2,dp);
    return dp[i][j] = 1+min({/*insertion*/solveMemoization(i,j-1,s1,s2,dp),/*Deletion*/solveMemoization(i-1,j,s1,s2,dp),/*Replacement*/solveMemoization(i-1,j-1,s1,s2,dp)});
}

int editDistance(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solveMemoization(n-1,m-1,s1,s2,dp);
}

//Tabulation
int editDistance(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 0; i<=n ;i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j<=m ;j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1;j <=m; j++)
        {
            if (s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    return dp[n][m];
}
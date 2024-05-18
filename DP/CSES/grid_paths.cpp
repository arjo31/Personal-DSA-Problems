#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solveMemoization(int row, int col, vector<vector<char>>&grid, vector<vector<int>>&dp)
{
    if (row==0 && col==0) return 1;
    if (row < 0 || col < 0) return 0;
    if (grid[row][col]=='*') return 0;
    if (dp[row][col]!=-1) return dp[row][col];
    int rightPath =  solveMemoization(row,col-1,grid,dp);
    int downPath = solveMemoization(row-1,col,grid,dp);
    return dp[row][col] = (rightPath + downPath) % MOD;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for (int i = 0; i < n; i++) for (int j =0 ;j < n; j++) cin>>grid[i][j];
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<((grid[0][0]=='*' || grid[n-1][n-1]=='*') ? 0 : solveMemoization(n-1,n-1,grid,dp))<<endl;
    return 0;
}
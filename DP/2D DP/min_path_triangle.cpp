#include <bits/stdc++.h>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

//Memoization
int solveMemoization(int row, int col, int n, vector<vector<int>>&triangle,unordered_map<pair<int,int>,int,pair_hash>&mpp)
{
    pair<int,int> key = make_pair(row,col);
    if (mpp.find(key)!=mpp.end())
    {
        return mpp[key];
    }
    if (row==n-1)
    {
        return mpp[key] = triangle[row][col];
    }
    if (row>n-1 || col>n-1)
    {
        return 1e9;
    }
    int downPath = solveMemoization(row+1,col,n,triangle,mpp) + triangle[row][col];
    int diagonalPath = solveMemoization(row+1,col+1,n,triangle,mpp) + triangle[row][col];
    mpp[key] = min(downPath,diagonalPath);
    return mpp[key];
}

int minPathTriangle(int n, vector<vector<int>>&triangle)
{
    unordered_map<pair<int,int>,int,pair_hash>mpp;
    return solveMemoization(0,0,n,triangle,mpp);
}

//Tabulation
int minPathTriangleTabulation(int n, vector<vector<int>>&triangle)
{
    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n ;i++)
    {
        for (int j = 0; j<=i; j++)
        {
            int diagPath = 1e9,upPath = 1e9;
            if (j < i)
            {
                upPath = dp[i-1][j] + triangle[i][j];
            }
            if (j > 0)
            {
                diagPath = dp[i-1][j-1] + triangle[i][j];
            } 
            dp[i][j] = min(diagPath,upPath);
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans,dp[n-1][i]);
    }
    return ans;
}
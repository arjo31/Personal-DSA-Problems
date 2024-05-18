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
int solveMemoization(int row,int col,int n,int m, vector<vector<int>>&matrix, unordered_map<pair<int,int>,int, pair_hash>&mpp)
{
    pair<int,int>key = {row,col};
    if (mpp.find(key)!=mpp.end())
    {
        return mpp[key];
    }
    if (row==n-1 && col>=0 && col < m)
    {
        return mpp[key] = matrix[row][col];
    }
    if (row > n-1 || col > m-1 || row < 0 || col < 0)
    {
        return 1e9;
    }
    int leftDiag = solveMemoization(row+1,col-1,n,m,matrix,mpp) + matrix[row][col];
    int down = solveMemoization(row+1,col,n,m,matrix,mpp) + matrix[row][col];
    int rightDiag = solveMemoization(row+1,col+1,n,m,matrix,mpp) + matrix[row][col];
    return mpp[key] = min({leftDiag,down,rightDiag});
}

int minFallingPathMemoization(vector<vector<int>>&matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 1e9;
    unordered_map<pair<int,int>,int,pair_hash>mpp;
    for (int i = 0; i < m ; i++)
    {
        ans = min(ans,solveMemoization(0,i,n,m,matrix,mpp));
    }
    return ans;
}

//Tabulation
int minFallingPathTabulation(vector<vector<int>>&matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = matrix[0][i];
    }
    for (int i = 1 ; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int leftDiag = 1e9, down = 1e9, rightDiag = 1e9;
            down = dp[i-1][j] + matrix[i][j];
            if (j==0) // Only down and right diagonal
            {
                rightDiag = dp[i-1][j+1] + matrix[i][j];
            }
            else if (j > 0 && j < m-1)
            {
                leftDiag = dp[i-1][j-1] + matrix[i][j];
                rightDiag = dp[i-1][j+1] + matrix[i][j];
            }
            else if (j==m-1)
            {
                leftDiag = dp[i-1][j-1] + matrix[i][j];
            }
            dp[i][j] = min({leftDiag,down,rightDiag});
        }
    }
    int ans = 1e9;
    for (int i = 0; i < m; i++)
    {
        ans = min(ans,dp[n-1][i]);
    }
    return ans;
}
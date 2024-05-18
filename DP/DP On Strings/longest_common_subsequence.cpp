#include <bits/stdc++.h>
using namespace std;

//Memoization
int solveMemoization(int ind1, int ind2, string s1, string s2, vector<vector<int>>&dp)
{
    if (ind1<0 || ind2<0)
    {
        return 0;
    }
    if (dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if (s1[ind1]==s2[ind2])
    {
        return dp[ind1][ind2] = 1 + solveMemoization(ind1-1, ind2-1,s1,s2,dp);
    }
    return dp[ind1][ind2] = 0 + max(solveMemoization(ind1-1,ind2,s1,s2,dp), solveMemoization(ind1,ind2-1,s1,s2,dp));
}

int lcsMemo(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solveMemoization(n-1,m-1,s1,s2,dp);
}

//Tabulation
int lcsTabulation(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 0; i <=n ;i++) dp[i][0] = 0;
    for (int j = 0; j <=m ;j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<=m ;j++)
        {
            if (s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];    
}

//Space Optimization
int lcsSO(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<int> prev(m+1,0), curr(m+1,0);
    for (int j = 0; j <=m ;j++) prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<=m ;j++)
        {
            if (s1[i-1]==s2[j-1])
            {
                curr[j] = 1 + prev[j-1];
            }
            else curr[j] = 0 + max(prev[j],curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];    
}
//Print the lcs
//dp[i][j] - > length of the lcs of string 1 of size i and string 2 of size j has length which is stored in dp[i][j]

string printlcsTabulation(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 0; i <=n ;i++) dp[i][0] = 0;
    for (int j = 0; j <=m ;j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<=m ;j++)
        {
            if (s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int len = dp[n][m];    
    string ans = "";
    for (int i = 0 ; i < len; i++)
    {
        ans+='#';
    }
    int ind = len - 1;
    int i = n, j = m;
    while (i>0 && j>0)
    {
        if (s1[i-1]==s2[j-1])
        {
            ans[ind] = s1[i-1];
            ind--;
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return ans;
}
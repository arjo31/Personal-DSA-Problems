#include <bits/stdc++.h>
using namespace std;

//Recursion formula : f(i,j) -> Length of LIS starting from ith index, whose prev index is j
//Memoization
int solveMemoization(int index, int prev_index, vector<int>&arr, vector<vector<int>>&dp)
{
    if (index==arr.size()) return 0;
    if (dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];
    //Nottake
    int notTake = 0 + solveMemoization(index+1,prev_index, arr,dp);
    int take = 0;
    if (prev_index==-1 || arr[index] > arr[prev_index])
    {
        take = 1 + solveMemoization(index+1,index,arr,dp);
    }
    dp[index][prev_index+1] = max(notTake,take);
    return dp[index][prev_index+1];
}

int lisMemoization(vector<int>&arr)
{
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(n+1,-1));

    return solveMemoization(0,-1,arr,dp);
}

//Tabulation
int lisTabulation(vector<int>&arr)
{
    int n = arr.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1,0));
    for (int ind = n-1; ind>=0; ind--)
    {
        for (int prevInd = ind - 1; prevInd>=-1; prevInd--)
        {
            int notTake = 0 + dp[ind+1][prevInd+1];
            int take = 0;
            if (prevInd==-1 || arr[ind]>arr[prevInd])
            {
                take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prevInd+1] = max(take,notTake);
        }
    }
    return dp[0][-1+1];
}

int lisTabulation2(vector<int>&arr)
{
    int n = arr.size();
    vector<int>dp(n,1), hash(n);
    int lastIndex = 0;
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1+dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int>list;
    list.push_back(arr[lastIndex]);
    while (hash[lastIndex]!=lastIndex)
    {
        lastIndex = hash[lastIndex];
        list.push_back(arr[lastIndex]);
    }
    reverse(list.begin(),list.end());
    for (auto it : list) cout<<it<<" ";
    cout<<endl;
    return maxi;
}

//Binary Search
//Subsequence is not created, but the length is found using this method. The most efficient method
//Lower bound function returns the index of arr[i] or the first index of the number > arr[i]
int lisBS(vector<int>&arr)
{
    int n = arr.size();
    vector<int>temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n ; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}
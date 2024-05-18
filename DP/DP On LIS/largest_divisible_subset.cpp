#include <bits/stdc++.h>
using namespace std;

/*Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.*/

int solveMemoization(int ind, int prevInd, vector<int>&arr, vector<vector<int>>&dp)
{
    if (ind==arr.size()) return 0;
    if (dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];
    int notTake = 0 + solveMemoization(ind + 1, prevInd,arr,dp);
    int take = 0;
    if (prevInd==-1 || arr[ind]%arr[prevInd]==0 || arr[prevInd]%arr[ind]==0)
    {
        take = 1 + solveMemoization(ind+1, ind,arr,dp);
    }
    dp[ind][prevInd+1] = max(take,notTake);
    return dp[ind][prevInd+1];
}

int largestDivisibleSubsetMemoization(vector<int>&arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n+1,-1));
    return solveMemoization(0,-1,arr,dp);
}

//Tabulation
int largestDivisibleSubsetTabulation(vector<int>&arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for (int ind = n-1; ind>=0; ind--)
    {
        for (int prevInd = ind-1; prevInd>=-1; prevInd--)
        {
            int notTake = dp[ind+1][prevInd+1];
            int take = 0;
            if (prevInd==-1 || arr[ind]%arr[prevInd]==0 || arr[prevInd]%arr[ind]==0)
            {
                take = 1 + dp[ind+1][ind];
            }
            dp[ind][prevInd+1] = max(take,notTake);
        }
    }
    return dp[0][-1+1];
}

vector<int> largestDivisibleSubsetTabulation2(vector<int>&arr)
{
    int n = arr.size();
    vector<int>dp(n,1), hash(n);
    int lastIndex = 0;
    int maxi = 1;
    sort(arr.begin(),arr.end());
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if ((arr[prev]%arr[i]==0 || arr[i]%arr[prev]==0) && 1+dp[prev] > dp[i])
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
    return list;
}

int main()
{
    vector<int>arr = {5,9,18,54,108,540,90,180,360,720};
    sort(arr.begin(),arr.end());
    vector<int>list = largestDivisibleSubsetTabulation2(arr);
    for (auto it : list) cout<<it<<" ";
    cout<<endl;
    cout<<largestDivisibleSubsetMemoization(arr)<<endl;
    return 0;
}
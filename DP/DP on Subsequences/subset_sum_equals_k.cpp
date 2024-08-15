/*Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum k.*/

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
bool solveMemoization(int index,vector<int>&arr, int target, unordered_map<pair<int,int>,int,pair_hash>&mpp)
{
    pair<int,int>key = {index,target};
    if (mpp.find(key)!= mpp.end())
    {
        return mpp[key];
    }
    if (target==0)
    {
        return mpp[key] = true;
    }
    if (index < 0 || target < 0)
    {
        return mpp[key] = false;
    }
    bool pick = solveMemoization(index-1,arr,target - arr[index],mpp);
    bool notpick = solveMemoization(index-1,arr,target,mpp);
    mpp[key] = pick||notpick;
    return mpp[key];
}

bool subsetSumMemoization(vector<int>&arr, int target)
{
    unordered_map<pair<int,int>,int,pair_hash>mpp;
    int n = arr.size();
    return solveMemoization(n-1,arr,target,mpp);
}

//Tabulation
bool subsetSumTabulation(vector<int>&arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target+1,false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0]<=target)
    {
        dp[0][arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k <= target; k++)
        {
            bool notTaken = dp[i - 1][k];
            bool taken = false;
            if (arr[i]<=k)
            {
                taken = dp[i - 1][k - arr[i]];
            }
            dp[i][k] = notTaken||taken;
        }
    }
    return dp[n-1][target];
}
/*Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.*/

#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int>&arr)
{
    int n = arr.size();
    unordered_map<int,int>mpp;
    long long int sum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if (sum==0)
        {
            ans = max(ans, i + 1);
        }
        if (mpp.count(sum)!=0)
        {
            ans = max(ans, i - mpp[sum]);
        }
        else
        {
            mpp[sum] = i;
        }
    }
    return ans;
}
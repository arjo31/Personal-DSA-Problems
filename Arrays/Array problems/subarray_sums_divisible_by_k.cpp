/*Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.*/

#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int prefixSum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += nums[i];
        int mod = prefixSum % k;
        if (mod < 0)
            mod += k;
        if (mpp.count(mod))
        {
            ans += mpp[mod];
            mpp[mod]++;
        }
        else
            mpp[mod] = 1;
    }
    return ans;
}
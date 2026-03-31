/*You are given a 0-indexed array nums consisting of positive integers.

A partition of an array into one or more contiguous subarrays is called good if no two subarrays contain the same number.

Return the total number of good partitions of nums.

Since the answer may be large, return it modulo 109 + 7.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int numberOfGoodPartitions(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]] = i;
    }
    int i = 0;
    int result = 1;
    int j = mpp[nums[0]];
    while (i < n)
    {
        if (i > j)
        {
            result = (result * 2) % MOD;
        }
        j = max(j, mpp[nums[i]]);
        i++;
    }
    return result;
}
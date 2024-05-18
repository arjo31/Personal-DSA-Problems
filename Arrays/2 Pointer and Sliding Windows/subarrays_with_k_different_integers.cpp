/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.*/

#include <bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return atMost(nums, k) - atMost(nums, k - 1);
}

int atMost(vector<int> &nums, int k)
{
    int n = nums.size();
    int r = 0;
    int l = 0;
    int count = 0;
    unordered_map<int, int> mpp;
    for (r = 0; r < n; r++)
    {
        k -= (mpp.find(nums[r]) == mpp.end());
        mpp[nums[r]]++;
        while (k < 0)
        {
            mpp[nums[l]]--;
            if (mpp[nums[l]] == 0)
                mpp.erase(nums[l]);
            k += (mpp.find(nums[l]) == mpp.end());
            l++;
        }
        count += r - l + 1;
    }
    return count;
}
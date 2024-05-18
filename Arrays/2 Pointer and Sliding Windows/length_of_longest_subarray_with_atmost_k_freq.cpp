/*You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int> &nums, int k)
{
    int l = 0;
    int r = 0;
    int n = nums.size();
    unordered_map<int, int> mpp;
    int length = 0;
    for (r = 0; r < n; r++)
    {
        mpp[nums[r]]++;
        while (mpp[nums[r]] > k)
        {
            mpp[nums[l]]--;
            l++;
        }
        length = max(length, r - l + 1);
    }
    return length;
}
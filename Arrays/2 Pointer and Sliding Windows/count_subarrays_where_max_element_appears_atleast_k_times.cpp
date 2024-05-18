/*You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.*/

#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int> &nums, int k)
{
    int maxElement = *max_element(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0;
    int r = 0;
    long long count = 0;
    for (r = 0; r < n; r++)
    {
        k -= (nums[r] == maxElement);
        while (k == 0)
        {
            count += n - r;
            k += (nums[l] == maxElement);
            l++;
        }
    }
    return count;
}
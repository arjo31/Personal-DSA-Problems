/*The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.*/

// Visit : https://www.youtube.com/watch?v=BZpF_o60STI for explanation

#include <bits/stdc++.h>
using namespace std;

bool countLessThanK(vector<int> &nums, int mid, int k)
{
    // Counting number of pairs having difference less than k
    int n = nums.size();
    int l = 0, r = 1, count = 0;
    for (r = 1; r < n; r++)
    {
        int diff = nums[r] - nums[l];
        while (nums[r] - nums[l] > mid)
        {
            l++;
        }
        count += (r - l);
    }
    return (count < k);
}

int smallestDistancePair(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums[n - 1] - nums[0];
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (countLessThanK(nums, mid, k))
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}
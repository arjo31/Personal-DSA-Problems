/*Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force : O(n log m) time and space O(m) : m = n/3 + 1
int singleNumber(vector<int> &nums)
{
    map<int, int> mpp;
    for (int num : nums)
        mpp[num]++;
    for (auto it : mpp)
        if (it.second == 1)
            return it.first;
    return -1;
}

// Optimal Method : time - O(n*32) and space : O(1)
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int bit = 0; bit < 32; bit++)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & (1 << bit))
                count++;
        }
        if (count % 3 == 1)
            ans = ans | (1 << bit);
    }
    return ans;
}

// Sorting : time - O(nlogn) and space : O(1)
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i += 3)
    {
        if (nums[i] != nums[i - 1])
            return nums[i - 1];
    }
    return nums[n - 1];
}

// Most optimal approach - O(n) time and O(1) space
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int ones = 0, twoes = 0;
    for (int i = 0; i < n; i++)
    {
        ones = (ones ^ nums[i]) & (~twoes);
        twoes = (twoes ^ nums[i]) & (~ones);
    }
    return ones;
}
/*Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.*/

#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (mpp.count(nums[i]))
        {
            if (abs(i - mpp[nums[i]]) <= k)
                return true;
            else
                mpp[nums[i]] = i;
        }
        else
        {
            mpp[nums[i]] = i;
        }
    }
    return false;
}
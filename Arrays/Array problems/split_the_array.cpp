/*You are given an integer array nums of even length. You have to split the array into two parts nums1 and nums2 such that:

nums1.length == nums2.length == nums.length / 2.
nums1 should contain distinct elements.
nums2 should also contain distinct elements.
Return true if it is possible to split the array, and false otherwise.*/

#include <bits/stdc++.h>
using namespace std;

bool isPossibleToSplit(vector<int> &nums)
{
    int n = nums.size();
    if (n & 1)
        return false;
    unordered_map<int, int> mpp;
    for (int i : nums)
    {
        mpp[i]++;
        if (mpp[i] > 2)
            return false;
    }
    return true;
}
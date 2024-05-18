// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxIdx = nums[0];

    for (int i = 0; i < n; i++)
    {
        if (maxIdx >= n - 1)
            return true;

        if (nums[i] == 0 && maxIdx == i)
            return false;

        if (i + nums[i] > maxIdx)
            maxIdx = i + nums[i];
    }
    return true;
}
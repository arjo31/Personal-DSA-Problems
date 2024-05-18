// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

#include <bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int prev = nums[i - 1];
        int curr = nums[i];
        if (curr < prev)
        {
            if (++count > 1)
                return false;

            if (i == 1 || nums[i - 2] <= curr)
                nums[i - 1] = nums[i];
            else
                nums[i] = nums[i - 1];
        }
    }
    return true;
}
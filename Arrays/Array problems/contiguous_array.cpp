//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    unordered_map<int, int> mpp;
    mpp[0] = -1;
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        int zeroes = i - sum + 1;
        if (mpp.count(sum - zeroes) != 0)
        {
            length = max(length, i - mpp[sum - zeroes]);
        }
        else
            mpp[sum - zeroes] = i;
    }
    return length;
}
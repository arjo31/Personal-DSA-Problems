/*You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.*/

#include <bits/stdc++.h>
using namespace std;

int isGreaterThanEqualTo(vector<int> &nums, int mid)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= mid)
            cnt++;
    }
    return cnt;
}

int specialArray(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = *max_element(nums.begin(), nums.end());
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isGreaterThanEqualTo(nums, mid) >= mid)
        {
            if (isGreaterThanEqualTo(nums, mid) == mid)
                ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
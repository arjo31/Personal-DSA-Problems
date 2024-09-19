/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.*/

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int sum = 0, prevDiff = INT_MAX;
    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int curSum = nums[i] + nums[left] + nums[right];
            int diff = abs(target - curSum);
            if (diff < prevDiff)
            {
                sum = curSum;
                prevDiff = diff;
            }
            if (target > curSum)
                left++;
            else
                right--;
        }
    }
    return sum;
}
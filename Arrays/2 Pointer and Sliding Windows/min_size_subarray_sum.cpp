/*Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.*/

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int r = 0;
    int l = 0;
    int sum = 0;
    int minLength = INT_MAX;
    for (r = 0; r < n; r++)
    {
        sum += nums[r];
        while (sum >= target)
        {
            minLength = min(minLength, r - l + 1);
            sum = sum - nums[l];
            l++;
        }
    }
    return (minLength != INT_MAX) ? minLength : 0;
}
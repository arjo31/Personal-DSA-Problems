/*You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it.

For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
Return the minimum number of operations to make an array that is sorted in non-decreasing order.*/

#include <bits/stdc++.h>
using namespace std;

long long minimumReplacement(vector<int> &nums)
{
    long long result = 0;
    int n = nums.size();
    int prev = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (prev >= nums[i])
        {
            prev = nums[i];
            continue;
        }
        int parts = ceil((double)nums[i] / (double)prev);
        result += (parts - 1);
        prev = nums[i] / (parts);
    }
    return result;
}
/*You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.*/

#include <bits/stdc++.h>
using namespace std;

int minIncrementForUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int prev = nums[0];
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] <= prev)
        {
            count += (prev - nums[i] + 1);
            nums[i] = prev + 1;
        }
        prev = nums[i];
    }
    return count;
}
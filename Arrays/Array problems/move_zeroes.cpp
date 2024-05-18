/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int ind = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
            nums[ind++] = nums[i];
    }
    while (ind < n)
    {
        nums[ind++] = 0;
    }
}
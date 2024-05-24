/*The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums.

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.*/

#include <bits/stdc++.h>
using namespace std;

// Recursive
int solve(int ind, int xorsum, vector<int> &nums)
{
    if (ind == nums.size())
        return xorsum;
    int x = nums[ind];
    int take = solve(ind + 1, xorsum ^ x, nums);
    int notTake = solve(ind + 1, xorsum, nums);

    return take + notTake;
}

int subsetXORSum(vector<int> &nums)
{
    return solve(0, 0, nums);
}

// Oneliner
int subsetXORSum(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum | nums[i];
    }
    return (sum << (n - 1));
}
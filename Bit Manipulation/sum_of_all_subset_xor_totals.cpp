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
/*Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.*/

#include <bits/stdc++.h>
using namespace std;

int countArrangement(int n)
{
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;
    vector<vector<int>> dp(n, vector<int>((1 << n), -1));
    return solve(0, (1 << n) - 1, nums, dp);
}

int solve(int ind, int bitmask, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind >= nums.size())
        return 1;
    if (dp[ind][bitmask] != -1)
        return dp[ind][bitmask];

    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (bitmask & (1 << i))
        {
            int newMask = bitmask ^ (1 << i);
            if (nums[i] % (ind + 1) == 0 || (ind + 1) % nums[i] == 0)
            {
                count = count + solve(ind + 1, newMask, nums, dp);
            }
        }
    }
    return dp[ind][bitmask] = count;
}
/*You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int numSubseq(vector<int> &nums, int target)
{
    // We can ignore subsequences because we only need min and max.. which can be any order.
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    vector<int> squares(n);
    squares[0] = 1;
    for (int i = 1; i < n; i++)
    {
        squares[i] = (2 * squares[i - 1]) % MOD;
    }
    int count = 0;
    while (l <= r)
    {
        if (nums[l] + nums[r] <= target)
        {
            count = (count + squares[r - l]) % MOD;
            l++;
        }
        else
            r--;
    }
    return count;
}
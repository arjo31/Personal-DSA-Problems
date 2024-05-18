/*Given an array of distinct integers nums and a target integer target, return the number of possible combinations (actually, permutations) that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(vector<int> &nums, int ind, int sum, vector<vector<int>> &dp)
{

    if (sum == 0)
        return dp[ind][sum] = 1;
    if (ind >= nums.size() || sum < 0)
        return 0;

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int notTake = 0 + solve(nums, ind + 1, sum, dp);
    int take = solve(nums, 0, sum - nums[ind], dp);
    return dp[ind][sum] = take + notTake;
}
int combinationSum4(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    solve(nums, 0, target, dp);
    return dp[0][target];
}

// Another Memoization
int solve(int i, vector<int> &nums, int target, vector<int> &dp, int n)
{
    int sum = 0;
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;
    if (dp[target] != -1)
        return dp[target];

    for (int j = 0; j < n; j++)
    {
        if (target >= nums[j])
        {

            sum += solve(j, nums, target - nums[j], dp, n);
        }
    }
    return dp[target] = sum;
}

int combinationSum4(vector<int> &nums, int target)
{

    vector<int> dp(target + 1, -1);
    int n = nums.size();
    return solve(0, nums, target, dp, n);
}

// Tabulation
int combinationSum4(vector<int> &nums, int target)
{
    vector<unsigned int> sumCount(target + 1);
    sumCount[0] = 1;
    int sz = nums.size();
    for (int sum = 1; sum <= target; sum++)
    {
        for (int indx = 0; indx < sz; indx++)
        {
            if (nums[indx] <= sum)
            {
                sumCount[sum] = (sumCount[sum] + sumCount[sum - nums[indx]]);
            }
        }
    }
    return sumCount[target];
}
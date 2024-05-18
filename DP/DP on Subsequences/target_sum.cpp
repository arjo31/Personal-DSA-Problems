/*You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.*/

#include <bits/stdc++.h>
using namespace std;

// This problem is the same as the partition sum difference

// Brute Force
int sumArray(vector<int> &arr, vector<char> &sign)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sign[i] == '+')
        {
            sum += arr[i];
        }
        else
        {
            sum -= arr[i];
        }
    }
    return sum;
}

void solve(int ind, vector<int> &arr, vector<char> &signs, int target, int &count)
{
    int sum = sumArray(arr, signs);
    if (sum == target)
    {
        count++;
        return;
    }
    if (ind < 0)
    {
        return;
    }
    signs[ind] = '-';
    solve(ind - 1, arr, signs, target, count);
    signs[ind] = '+';
    solve(ind - 1, arr, signs, target, count);
}

int targetSumBF(int n, vector<int> &arr, int target)
{
    vector<char> signs(n, '+');
    int count = 0;
    solve(n - 1, arr, signs, target, count);
    return count;
}

// Memoization
int solveMemoization(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (k == 0 && arr[0] == 0)
            return 2;
        if (k == 0 || k == arr[0])
            return 1;
        return 0;
    }
    if (dp[n][k] != -1)
        return dp[n][k];
    int notTake = solveMemoization(n - 1, k, arr, dp);
    int take = 0;
    if (arr[n] <= k)
    {
        take = solveMemoization(n - 1, k - arr[n], arr, dp);
    }
    dp[n][k] = notTake + take;
    return dp[n][k];
}

int countSubsetsMemoization(int n, int d, vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum - d) % 2 != 0 || (sum - d) < 0)
        return 0;
    int k = (sum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    return solveMemoization(n - 1, k, arr, dp);
}

// Tabulation
int countPartitionsTabulation(int n, int d, vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum - d) % 2 != 0 || (sum - d) < 0)
        return 0;
    int k = (sum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= k && arr[0] != 0)
    {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= k; target++)
        {
            int take = 0;
            int notTake = dp[i - 1][target];
            if (arr[i] <= target)
                take = dp[i - 1][target - arr[i]];
            dp[i][target] = (notTake + take) % (int)(1e9 + 7);
        }
    }
    return dp[n - 1][k];
}
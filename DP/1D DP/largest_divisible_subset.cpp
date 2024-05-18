/*Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    int lastIndex = 0;
    int maxi = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if ((nums[prev] % nums[i] == 0 || nums[i] % nums[prev] == 0) && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> list;
    list.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        list.push_back(nums[lastIndex]);
    }
    reverse(list.begin(), list.end());
    return list;
}
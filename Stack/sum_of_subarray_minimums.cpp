/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int sumSubarrayMins(vector<int> &nums)
{
    int length = nums.size();
    vector<int> left(length, -1);
    vector<int> right(length, length);
    stack<int> stk;

    // Previous Smallest element
    for (int i = 0; i < length; ++i)
    {
        while (!stk.empty() && nums[stk.top()] >= nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            left[i] = stk.top();
        }
        stk.push(i);
    }

    stk = stack<int>();

    // Next Smallest Element
    for (int i = length - 1; i >= 0; --i)
    {
        while (!stk.empty() && nums[stk.top()] > nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            right[i] = stk.top();
        }
        stk.push(i);
    }

    ll sum = 0;

    for (int i = 0; i < length; ++i)
    {
        sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
        sum %= MOD;
    }

    return sum;
}
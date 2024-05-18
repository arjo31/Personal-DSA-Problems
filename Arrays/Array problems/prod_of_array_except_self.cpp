/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> prodOfArrayExceptSelf(vector<int> &arr)
{
    int n = arr.size();
    vector<int> suff(n);
    vector<int> pref(n);
    vector<int> ans(n);
    suff[0] = 1;
    pref[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        suff[i] = suff[i - 1] * arr[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        pref[i] = pref[i + 1] * arr[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = suff[i] * pref[i];
    }
    return ans;
}

// TC : O(n) && SC : O(1)
vector<int> productExceptSelf(vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n);

    output[0] = 1;
    for (int i = 1; i < n; i++)
    {
        output[i] = arr[i - 1] * output[i - 1];
    }

    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        output[i] = output[i] * right;
        right = right * arr[i];
    }
    return output;
}
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//Maximum subarray sum
long long int maxSubarraySum(vector<int>&arr)
{
    int n = arr.size();
    long long sum = 0;
    long long ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if (ans < sum)
        {
            ans = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return ans;
}
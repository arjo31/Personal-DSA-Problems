/*Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.*/

#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int k, vector<int>&arr)
{
    int n = arr.size();
    int i = 0;
    int j = 0;
    long sum = 0;
    while (j < k)
    {
        sum+=arr[j];
        j++;
    }
    long ans = sum;
    while (j < n)
    {
        sum+=arr[j++] - arr[i++];
        ans = max(sum, ans);
    }
    return ans;
}
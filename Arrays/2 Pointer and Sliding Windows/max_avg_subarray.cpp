// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.Any answer with a calculation error less than 10 -
// 5 will be accepted.

#include <bits/stdc++.h>
using namespace std;

double max(double a, double b)
{
    if (a > b)
        return a;
    return b;
}

double findMaxAverage(vector<int> &nums, int k)
{
    double sum = 0;
    int n = nums.size();
    int i;
    for (i = 0; i < k; i++)
        sum += nums[i];
    double avg = sum / (double)k;
    double maxAvg = INT_MIN;
    maxAvg = max(maxAvg, avg);
    while (i < n)
    {
        sum = sum - nums[i - k] + nums[i];
        avg = sum / (double)k;
        maxAvg = max(maxAvg, avg);
        i++;
    }
    return maxAvg;
}
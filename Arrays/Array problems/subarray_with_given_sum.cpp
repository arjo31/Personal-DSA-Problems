#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

// In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

// Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

vector<int>subarraySum(vector<int>&arr, long long target)
{
    int n = arr.size();
    int i = 0, j = 0;
    long long sum = 0;
    for (int k = 0; k < n; k++)
    {
        sum+=arr[k];
        
        if (sum>=target)
        {
            j = k;
            while (i < j && sum > target)
            {
                sum = sum - arr[i];
                i++;
            }
        }

        if (sum==target)
        {
            return {i+1, j+1};
        }
    }
    return {-1};
}
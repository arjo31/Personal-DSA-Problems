/*Given an integer array ‘A’ of size ‘N’ and an integer ‘K’. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.*/

#include <bits/stdc++.h>
using namespace std;

int noOfPartitions(vector<int>&arr, int limitSum)
{
    int n = arr.size();
    int countPartitions = 1;
    int prevSumOfPartitions = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] + prevSumOfPartitions > limitSum)
        {
            countPartitions++;
            prevSumOfPartitions = arr[i];
        }
        else
        {
            prevSumOfPartitions+=arr[i];
        }
    }
    return countPartitions;
}

int minLargestSum(vector<int>&arr, int k)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low<=high)
    {
        int mid = low + (high - low)/2;

        if (noOfPartitions(arr,mid) > k)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
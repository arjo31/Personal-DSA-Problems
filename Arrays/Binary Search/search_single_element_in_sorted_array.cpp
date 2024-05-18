//Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array. The array is sorted.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int searchSingleEle(vector<int>&arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (mid&1)
        {
            if (arr[mid-1]==arr[mid]) low = mid + 1;
            else high = mid - 1;
        }
        else
        {
            if (arr[mid]==arr[mid+1]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return arr[low];
}
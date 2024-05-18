//Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int searchInRotatedSortedArray(vector<int>&arr, int x)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[low] <= arr[mid])
        {
            if (arr[low]<=x && x <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= x && x<=arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
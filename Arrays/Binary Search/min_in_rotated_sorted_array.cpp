// Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int minInRotatedArray(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int minEle = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high])
        {
            minEle = min(minEle, arr[low]);
            break;
        }

        if (arr[low] <= arr[mid])
        {
            minEle = min(minEle, arr[low]);
            low = mid + 1;
        }
        else
        {
            minEle = min(minEle, arr[mid]);
            high = mid - 1;
        }
    }
    return minEle;
}
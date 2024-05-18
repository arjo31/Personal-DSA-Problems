//Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

//No of rotations = Index of the minimum element

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int noOfRotations(vector<int>&arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int  mid = low + (high - low)/2;

        if (arr[low]<=arr[high])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}
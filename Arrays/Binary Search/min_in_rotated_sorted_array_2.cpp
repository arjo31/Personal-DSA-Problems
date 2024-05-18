/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }
        else if (arr[mid] <= arr[high])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return arr[low];
}
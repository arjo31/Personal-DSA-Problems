//The floor of x is the largest element in the array which is smaller than or equal to x.
//The ceiling of x is the smallest element in the array greater than or equal to x.

//[1,3,5,6,8,8,9], x = 7 => floor(x) = 6, ceil(x) = 8;

#include <bits/stdc++.h>
using namespace std;

int floor(vector<int>&arr, int x)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int floor = n-1;
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid]<=x)
        {
            floor = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return arr[floor];
}

int ceil(vector<int>&arr, int x)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int ceil = n-1;
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid]<=x)
        {
            ceil = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return arr[ceil];
}
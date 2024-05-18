/*Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

1. Increase the height of the tower by K
2. Decrease the height of the tower by K

Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.*/

#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int initDiff = arr[n-1] - arr[0];
    int tempMax = arr[n-1];
    int tempMin = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - k < 0) continue;
        int x = arr[i];
        tempMax = max(arr[i-1] + k, arr[n-1] - k);
        tempMin = min(arr[0] + k, x - k);
        initDiff = min(tempMax - tempMin, initDiff);
    }
    return initDiff;
}
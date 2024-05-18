#include <bits/stdc++.h>
using namespace std;

//Given an array A of n positive numbers. The task is to find the first equilibrium point in an array. Equilibrium point in an array is an index (or position) such that the sum of all elements before that index is same as sum of elements after it.

//Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

int equilibriumPoint(long long arr[], int n)
{
    if (n==1) return 1;
    
    long long left = arr[0], right = arr[n-1];
    int i = 1, j = n - 2;
    while (i <= j)
    {
        if (left > right)
        {
            right+=arr[j--];
        }
        else if (left < right)
        {
            left+=arr[i++];
        }
        else if (left==right)
        {
            if (i==j) return i+1;
            else
            {
                left+=arr[i++];
                right+=arr[j--];
            }
        }
    }
    return -1;
}
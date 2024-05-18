/*Given an array of N elements and L and R, print the number of sub-arrays such that the value of the maximum array element in that subarray is at least L and at most R.*/

#include <bits/stdc++.h>
using namespace std;

long countSubarrays(int arr[], int n, int L, int R)
{
    long count = 0;
    long l = 0,r = 0;
    int i = 0;
    while ( i < n )
    {
        if (arr[i] < L)
        {
            l++;
            r++;
        }
        else if (arr[i] > R)
        {
            count+=l*(l+1)/2 - r*(r+1)/2;
            l = 0;
            r = 0;
        }
        else
        {
            count-=r*(r+1)/2;
            r = 0;
            l++;
        }
        i++;
    }
    count+=l*(l+1)/2 - r*(r+1)/2;
    return count;
}
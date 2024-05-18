 //You are given an array of integers ‘arr’ and an integer i.e. a threshold value ‘limit’. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division’s result is less than or equal to the given threshold value.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int sum(vector<int>&arr, int div)
{
    int n = arr.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total+=(arr[i]/div) + ((arr[i]%div)!=0);
    }
    return total;
}

int smallestDivisor(vector<int>&arr, int limit)
{
    int low = 1,high = *max_element(arr.begin(),arr.end());
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if (sum(arr,mid) <= limit)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
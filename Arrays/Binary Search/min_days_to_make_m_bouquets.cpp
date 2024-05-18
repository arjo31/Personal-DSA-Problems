/*You are given ‘N’ roses and you are also given an array ‘arr’  where ‘arr[i]’  denotes that the ‘ith’ rose will bloom on the ‘arr[i]th’ day. You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly ‘k’ adjacent bloomed roses to make a single bouquet.
Find the minimum number of days required to make at least ‘m’ bouquets each containing ‘k’ roses. Return -1 if it is not possible.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int noOfBouquets(vector<int>&arr, int k, int days)
{
    int n = arr.size();
    int groupCount = 0;
    int count = 0;
    for (int i = 0; i<n; i++)
    {
        if (arr[i]<=days)
        {
            count++;
        }
        else
        {
            groupCount+=(count/k);
            count = 0;
        }
    }
    groupCount+=(count/k);
    return groupCount;
}

int minDays(vector<int>&arr,int m, int k)
{
    if (m*k > arr.size()) return -1;
    int low = *min_element(arr.begin(),arr.end()),high = *max_element(arr.begin(),arr.end());
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (noOfBouquets(arr,k,mid)>=m)
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
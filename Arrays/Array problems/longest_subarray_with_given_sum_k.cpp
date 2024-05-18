/*Given an array and a sum k, we need to print the length of the longest subarray that sums to k.*/

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : TC : O(n^2) and SC : O(1)
int longestSubarrayWithSumK(vector<int>&arr, int k)
{
    int n = arr.size();
    int len = 0;
    for (int i = 0 ; i < n; i++)
    {
        long long s = 0;
        for (int j = i; j < n; j++)
        {
            s+=arr[j];
            if (s==k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

//Approach 2 : TC : O(n) and SC : O(n)
int longestSubarrayWithSumK(vector<int>&arr, int k)
{
    int n = arr.size();
    unordered_map<long long int,int>mpp;
    long long s = 0; 
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        s+=arr[i];
        if (s==k)
        {
            len = max(len, i+1);
        }
        long long rem = s - k;

        if (mpp.find(rem)!=mpp.end())
        {
            len = max(len, i - mpp[rem]);
        }
        if (mpp.find(s)==mpp.end())
        {
            mpp[s] = i;
        }
    }
    return len;
}

//Approach 3 : TC : O(n) and SC : O(1)
int longestSubarrayWithSumK(vector<int>&arr, int k)
{
    int n = arr.size();
    int i = 0;
    int j = 0;
    long long sum = 0;
    int len = 0;
    while (j < n)
    {
        while (i<=j && sum > k)
        {
            sum = sum - arr[i++];
        }
        if (sum==k)
        {
            len = max(len, j - i + 1);
        }
        j++;
        if (j < n) sum+=arr[j];
    }
    return len;
}
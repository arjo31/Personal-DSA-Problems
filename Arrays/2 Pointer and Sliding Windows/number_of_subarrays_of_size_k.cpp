/*Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.*/

#include <bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    long sum = 0;
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int count = 0;
    long avg = sum / k;
    if (avg >= threshold)
        count++;
    int i = 0;
    int j = k;
    while (j < n)
    {
        sum = sum - arr[i++] + arr[j++];
        avg = sum / k;
        if (avg >= threshold)
            count++;
    }
    return count;
}
/*Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.*/

#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    long sum = 0;
    unordered_set<int>s;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if (sum==0 || s.count(sum)!=0) return true;
        s.insert(sum);
    }
    return false;
}
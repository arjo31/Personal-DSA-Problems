/*Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int>largestPermutation(vector<int>&arr, int b)
{
    int n = arr.size();
    int pos[n+1];
    for (int i = 0; i < n; i++)
    {
        pos[arr[i]] = i;
    }

    for (int i = 0; i < n && b; i++)
    {
        if (arr[i]==n-i) continue;

        int temp = pos[n-i];
        pos[arr[i]] = pos[n-i];
        pos[n-i] = i;

        swap(arr[temp], arr[i]);

        b--;
    }
    return arr;
}
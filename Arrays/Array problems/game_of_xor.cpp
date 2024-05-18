//Given an array A of size N. The value of an array is denoted by the bit-wise XOR of all elements it contains. Find the bit-wise XOR of the values of all subarrays of A.

//From observation element at index i is at a frequency (i+1)*(N-i). If freq is odd => find xor

#include <bits/stdc++.h>
using namespace std;

int gameOfXORS(vector<int>&arr)
{
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int freq = (i + 1)*(n - i);
        if (freq&1) ans = ans^arr[i];
    }
    return ans;
}
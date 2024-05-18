/*Let us first understand what a bitonic subsequence means.

A bitonic subsequence is a subsequence of an array in which the elements can be any of these three:

First, increase till a point and then decrease.
Goes on increasing (Longest increasing subsequence)
Goes on decreasing (Longest decreasing subsequence)*/

#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>&arr)
{
    int n = arr.size();
    vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence ending at arr[i]
    vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence ending at arr[i]

    // Calculate the longest increasing subsequence
    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i]) {
                dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
            }
        }
    }

    // Reverse the direction of nested loops to calculate the longest decreasing subsequence
    for (int i = n - 1; i >= 0; i--) {
        for (int prev_index = n - 1; prev_index > i; prev_index--) {
            if (arr[prev_index] < arr[i]) {
                dp2[i] = max(dp2[i], 1 + dp2[prev_index]);
            }
        }
    }

    int maxi = -1;

    // Find the maximum length of the bitonic subsequence
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}

int main()
{
    vector<int>arr = {1,11,2,10,4,5,2,1};
    cout<<longestBitonicSubsequence(arr)<<endl;
}
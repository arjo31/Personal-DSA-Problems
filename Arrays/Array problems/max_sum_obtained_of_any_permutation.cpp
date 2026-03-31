/*We have an array of integers, nums, and an array of requests where requests[i] = [starti, endi]. The ith request asks for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi]. Both starti and endi are 0-indexed.

Return the maximum total sum of all requests among all permutations of nums.

Since the answer may be too large, return it modulo 109 + 7.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//Line Sweep / Diff array technique
int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
{
    int n = nums.size();
    vector<int> freq(n, 0);
    int sum = 0;
    for (auto request : requests)
    {
        freq[request[0]]++;
        if (request[1] + 1 < n)
            freq[request[1] + 1]--;
    }
    for (int i = 1; i < n; i++)
        freq[i] = freq[i] + freq[i - 1];
    sort(freq.begin(), freq.end());
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        sum = (sum + (1LL * freq[i] * nums[i]) % MOD) % MOD;
    }
    return sum % MOD;
}
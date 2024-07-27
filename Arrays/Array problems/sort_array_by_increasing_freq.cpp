/*Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(201, 0);
    for (int i = 0; i < n; i++)
    {
        freq[nums[i] + 100]++;
    }
    sort(nums.begin(), nums.end(), [&](int a, int b)
         {
            if (freq[a + 100]==freq[b + 100]) return a > b;
            return freq[a + 100] < freq[b + 100]; });
    return nums;
}
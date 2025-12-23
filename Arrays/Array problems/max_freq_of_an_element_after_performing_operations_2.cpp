/*You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing the operations.*/

/*Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= k <= 10^9
0 <= numOperations <= nums.length*/

// Youtube link : https://www.youtube.com/watch?v=hSyXvam4Us4&list=PLpIkg8OmuX-Kqkb8DqDe_4-Tiav6ilS_L&index=6

#include <bits/stdc++.h>
using namespace std;

// Difference array + map -> O(Nlogn)
int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end()) + k;
    unordered_map<int, int> freq;
    map<int, int> prefix;

    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
        int l = max(0, nums[i] - k);
        int r = min(maxVal, nums[i] + k);
        prefix[l] += 1;
        prefix[r + 1] -= 1;
        prefix[nums[i]] += 0;
    }

    int ans = 1;
    int cumSum = 0;
    for (auto it = prefix.begin(); it != prefix.end(); it++)
    {
        int target = it->first;
        it->second += cumSum;
        int elementOwnFreq = freq[target];
        int elementsNeedingConversion = prefix[target] - elementOwnFreq;
        int maxPossibleConversions = min(numOperations, elementsNeedingConversion);
        ans = max(ans, elementOwnFreq + maxPossibleConversions);
        cumSum = it->second;
    }
    return ans;
}
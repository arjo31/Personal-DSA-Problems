/*You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing the operations.*/

// Youtube link for explanation : https://www.youtube.com/watch?v=BaEebscdBJM&list=PLpIkg8OmuX-Kqkb8DqDe_4-Tiav6ilS_L&index=5

/*Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
0 <= k <= 10^5
0 <= numOperations <= nums.length
*/

// Difference array + maxVal array -> Space -> O(maxVal) -> not suitable if maxVal > 10^8
#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end()) + k;
    unordered_map<int, int> freq;
    vector<int> prefix(maxVal + 2, 0);

    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
        int l = max(0, nums[i] - k);
        int r = min(maxVal, nums[i] + k);
        prefix[l] += 1;
        if (r + 1 < n)
            prefix[r + 1] -= 1;
    }

    int ans = 1;
    for (int i = 0; i <= maxVal; i++)
    {
        prefix[i] += (i > 0 ? prefix[i - 1] : 0);
        int elementOwnFreq = freq[i];
        int elementsNeedingConversion = prefix[i] - elementOwnFreq;
        int maxPossibleConversions = min(numOperations, elementsNeedingConversion);
        ans = max(ans, elementOwnFreq + maxPossibleConversions);
    }
    return ans;
}
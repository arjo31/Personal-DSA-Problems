/*You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> ans(n);

    for (int i = 0; i < n; i++)
    {
        int ogNum = nums[i];
        int mappedNum = (ogNum == 0) ? mapping[0] : 0;
        int placeVal = 1;
        while (ogNum > 0)
        {
            int digit = ogNum % 10;
            mappedNum = mappedNum + placeVal * mapping[digit];
            ogNum /= 10;
            placeVal *= 10;
        }

        ans[i] = {mappedNum, i};
    }

    sort(ans.begin(), ans.end());

    vector<int> final;
    for (auto it : ans)
    {
        final.push_back(nums[it.second]);
    }

    return final;
}
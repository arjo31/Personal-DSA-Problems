/*Given a number 'N', you need to find all possible unique ways to represent this number as the sum of positive integers.

Note
1. By unique it is meant that no other composition can be expressed as a permutation of the generated composition. For eg. [1, 2, 1] and [1, 1, 2] are not unique.

2. You need to print all combinations in non-decreasing order for eg. [1, 2, 1] or [1, 1, 2] will be printed as [1, 1, 2], however, the order of printing all the sequences can be random. */

#include <bits/stdc++.h>
using namespace std;

void breakNumberHelper(int start, int rem, vector<int> &arr, vector<vector<int>> &ans)
{
    if (!rem)
    {
        ans.push_back(arr);
        return;
    }
    for (int i = start; i <= rem; i++)
    {
        arr.push_back(i);
        breakNumberHelper(i, rem - i, arr, ans);
        arr.pop_back();
    }
}

vector<vector<int>> breakNumber(int n)
{
    vector<vector<int>> ans;
    vector<int> arr;
    breakNumberHelper(1, n, arr, ans);
    return ans;
}
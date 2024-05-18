// You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Approach 1 : O(nlogn) + O(n)
int longestSequence(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int count = 0;
    int longest = 1;
    int lastSmallest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastSmallest)
        {
            count++;
            lastSmallest = arr[i];
        }
        else if (arr[i] != lastSmallest)
        {
            count = 1;
            lastSmallest = arr[i];
        }
        longest = max(count, longest);
    }
    return longest;
}

// Approach 2: O(3*n)
int longestSequenceSet(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> s;
    for (int element : arr)
        s.insert(element);
    int longest = INT_MIN;
    for (auto it : s)
    {
        if (s.find(it - 1) == s.end()) // Not found
        {
            int count = 1;
            int x = it;
            while (s.find(x + 1) != s.end())
            {
                x = x + 1;
                count = count + 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}
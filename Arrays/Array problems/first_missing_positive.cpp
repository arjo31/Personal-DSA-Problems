/*Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.*/

#include <bits/stdc++.h>
using namespace std;

// TC : O(n) and SC : O(n)
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, bool> mpp;
    for (int i : nums)
    {
        mpp[i] = true;
    }
    int maxElement = *max_element(nums.begin(), nums.end());
    for (int i = 1; i < maxElement; i++)
    {
        if (mpp.find(i) == mpp.end())
            return i;
    }
    return (maxElement < 0 ? 1 : maxElement + 1);
}

// TC : O(nlogn) and SC : O(n)
int firstMissingPositive(vector<int> &v)
{
    int n = v.size();
    set<int> s;
    for (auto i : v)
        s.insert(i);
    for (int i = 1; i <= 100001; i++)
    {
        if (s.find(i) == s.end())
            return i;
    }
    return 0;
}

// Binary Search : TC : O(nlogn) and SC : O(1)
bool search(int k, vector<int> &v)
{
    int i = 0, j = v.size() - 1;
    while (i <= j)
    {
        int m = (i + j) / 2;
        if (k == v[m])
            return false;
        if (k > v[m])
            i = m + 1;
        else
            j = m - 1;
    }
    return true;
}
int firstMissingPositive(vector<int> &v)
{
    int n = v.size();
    sort(v.begin(), v.end());
    for (int i = 1; i <= 100001; i++)
    {
        if (search(i, v))
            return i;
    }
    return 0;
}

// TC : O(n) and SC : O(n)
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> seen(n + 1, false);
    // Mark the elements from nums in the lookup array
    for (int num : nums)
    {
        if (num > 0 && num <= n)
        {
            seen[num] = true;
        }
    }
    // Iterate through integers 1 to n
    // return smallest missing positive integer
    for (int i = 1; i <= n; i++)
    {
        if (!seen[i])
        {
            return i;
        }
    }
    // If seen contains all elements 1 to n
    // the smallest missing positive number is n + 1
    return n + 1;
}

// Best : Cyclic Sort : TC : O(n) and SC : O(1)
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();

    // Use cycle sort to place positive elements smaller than n
    // at the correct index
    int i = 0;
    while (i < n)
    {
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
        else
        {
            i++;
        }
    }

    // Iterate through nums
    // return smallest missing positive integer
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }

    // If all elements are at the correct index
    // the smallest missing positive number is n + 1
    return n + 1;
}
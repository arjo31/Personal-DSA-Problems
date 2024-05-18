#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Using map : O(nlogn) + O(n) , unordered map : O(n) best and O(n^2) worst
int majorityElementMap(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    for (int ele : arr)
    {
        mpp[ele]++;
    }
    int ans = -1;
    for (auto pair : mpp)
    {
        if (pair.second > n / 2)
        {
            ans = pair.first;
        }
    }
    return ans;
}

// Moore's Voting Algorithm : O(n)
int majorityElement(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    int ele;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            ele = arr[i];
        }
        else if (ele == arr[i])
            count++;
        else
            count--;
    }

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
            count1++;
    }

    if (count1 > (n / 2))
        return ele;
    return -1;
}
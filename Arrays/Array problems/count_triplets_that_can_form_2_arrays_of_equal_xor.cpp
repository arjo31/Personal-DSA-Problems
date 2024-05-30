/*Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force : O(n^3)
int countTriplets(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int a = 0;
            for (int k = i; k < j; ++k)
            {
                a ^= arr[k];
            }

            int b = 0;
            for (int k = j; k < n; ++k)
            {
                b ^= arr[k];
                if (a == b)
                {
                    ++count;
                }
            }
        }
    }
    return count;
}

// Optimized : O(n^2)
int countTriplets(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;

    vector<int> prefXor(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefXor[i + 1] = prefXor[i] ^ arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (prefXor[i] == prefXor[j + 1])
                count += (j - i);
        }
    }
    return count;
}

//Another Method
int countTriplets(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, vector<int>>mpp;
    mpp[0].push_back(-1);
    int x = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        x^=arr[i];
        if (mpp.find(x)!=mpp.end())
        {
            for (auto a : mpp[x])
            {
                ans+=(i - (a + 1));
            }
        }
        mpp[x].push_back(i);
    }
    return ans;
}
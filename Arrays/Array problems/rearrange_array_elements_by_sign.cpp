// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> rearrangeArray(vector<int> &arr)
{
    int n = arr.size();

    int pos = 0, neg = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            arr[neg] = arr[i];
            neg += 2;
        }
        else
        {
            arr[pos] = arr[i];
            pos += 2;
        }
    }
    return arr;
}
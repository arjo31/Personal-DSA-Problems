// Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> leader(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    int matchingElement = arr[n - 1];
    ans.push_back(matchingElement);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > matchingElement)
        {
            matchingElement = arr[i];
            ans.push_back(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
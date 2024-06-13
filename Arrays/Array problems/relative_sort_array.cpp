/*Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    map<int, int> mpp;
    for (int num : arr1)
        mpp[num]++;
    vector<int> ans;
    for (int num : arr2)
    {
        if (mpp.count(num))
        {
            while (mpp[num]--)
                ans.push_back(num);
            mpp.erase(num);
        }
    }

    for (auto it : mpp)
    {
        while (it.second--)
            ans.push_back(it.first);
        mpp.erase(it.first);
    }
    return ans;
}
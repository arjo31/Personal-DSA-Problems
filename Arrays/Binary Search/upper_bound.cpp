//The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

//The upper bound is the smallest index, ind, where arr[ind] > x.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int upperBound(vector<int>arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int upperBoundIndex = n;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid]>target)
        {
            upperBoundIndex = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return upperBoundIndex;
}
//STL : upper_bound();
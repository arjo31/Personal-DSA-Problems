//The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

//The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int lowerBound(vector<int>arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int lowerBoundIndex = n;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid]>=target)
        {
            lowerBoundIndex = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return lowerBoundIndex;
}
//STL : lower_bound()
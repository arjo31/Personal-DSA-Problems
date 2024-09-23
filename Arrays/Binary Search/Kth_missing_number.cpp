// You are given a strictly increasing array 'vec' and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int missingK(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    int more = k - (arr[high] - (high + 1));
    return arr[high] + more;
}

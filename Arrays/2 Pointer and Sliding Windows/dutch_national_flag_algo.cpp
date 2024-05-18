//Sort an array of 0's, 1's and 2's in O(n) TC and O(1) SC

#include <bits/stdc++.h>
using namespace std;

void DNFAlgo(vector<int>&arr)
{
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid]==0)
        {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid]==1) mid++;
        else if (arr[mid]==2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
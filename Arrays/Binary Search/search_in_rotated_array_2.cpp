//Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

bool searchInRotatatedArray2(vector<int>&arr, int x)
{
    int n = arr.size();
    int low = 0, high = n-1;
    while (low <= high)
    {
        int mid = low + (high - low)/2;

        if (arr[mid]==x) return true;

        //Edge case : 
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= x && x <= arr[high])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= x && x <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}
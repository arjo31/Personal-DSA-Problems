/*You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within ‘d’ days.
The weights of the packages are given in an array ‘of weights’. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
Find out the least-weight capacity so that you can ship all the packages within ‘d’ days.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int days(vector<int>&arr, int maxCap)
{
    int n = arr.size();
    int noOfDays = 1;
    int load = 0;
    for (int i = 0; i < n; i++)
    {
        if (load + arr[i] > maxCap)
        {
            noOfDays++;
            load = arr[i];
        }
        else
        {
            load+=arr[i];
        }
    }
    return noOfDays;
}

int weightCapacity(vector<int>&arr, int d)
{
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if (days(arr,mid)<=d)
        {
            cout<<mid<<" "<<days(arr,mid)<<endl;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
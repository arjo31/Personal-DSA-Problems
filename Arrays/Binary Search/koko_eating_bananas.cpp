/*A monkey is given ‘n’ piles of bananas, whereas the ‘ith’ pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long hours(vector<int>&arr, int h, int k)
{
    int n = arr.size();
    long long hours = 0;
    for (int i = 0 ; i < n; i++)
    {
        hours+=arr[i]/k + ((arr[i]%k)!=0);
    }
    return hours;
}

int minimumBananas(vector<int>&arr, int h)
{
    int high = *max_element(arr.begin(), arr.end());
    int low = 1;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (hours(arr,h,mid) <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
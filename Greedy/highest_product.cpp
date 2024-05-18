/*Find the highest product by multiplying 3 elements*/

#include <bits/stdc++.h>
using namespace std;

int highestProduct(vector<int>&arr)
{
    sort(arr.begin(),arr.end());
    int n = arr.size();
    return max(arr[0]*arr[1]*arr[n-1], arr[n-1]*arr[n-2]*arr[n-3]);
}
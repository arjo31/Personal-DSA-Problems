#include <bits/stdc++.h>
using namespace std;

long long int solve(int ind, vector<long long int>&arr, long long int target)
{
    if (target==0) return 1;
    if (ind==0)
    {
        if (arr[ind]==target)
        {
            return 1;
        }
        return 0;
    }

    long long int notTake = solve(ind - 1, arr, target);
    long long int take = 0;
    if (arr[ind] <= target)
    {
        take = solve(ind - 1, arr, target - arr[ind]);
    }
    return take + notTake;
}

int main()
{
    long long int n,x;
    cin>>n>>x;
    vector<long long int>arr(n);
    for (long long int i = 0; i < n; i++) cin>>arr[i];
    cout<<solve(n-1,arr,x)<<endl;
    return 0;
}
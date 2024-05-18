#include <bits/stdc++.h>
using namespace std;

//O(n^2)
// int solveMemoization(int prev, int curr, vector<int> &arr, vector<vector<int>>&dp)
// {
//     if (curr==arr.size()) return 0;
//     if (dp[prev+1][curr]!=-1) return dp[prev+1][curr];
//     int notTake = 0 + solveMemoization(prev,curr+1,arr,dp);
//     int take = 0;
//     if (prev==-1 || arr[prev] < arr[curr])
//     {
//         take = 1 + solveMemoization(curr, curr + 1, arr,dp);
//     }
//     return dp[prev+1][curr] = max(take,notTake);
// }

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];
    vector<int>temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    cout<<temp.size()<<endl;
    return 0;
}
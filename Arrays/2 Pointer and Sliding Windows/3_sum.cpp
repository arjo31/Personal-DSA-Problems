#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>&arr, int target)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>>ans;
    for(int i = 0; i < n - 1; i++)
    {
        int j = i+1;
        int k = n-1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum==target)
            {
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
            else if (sum < target) j++;
            else k--;
        }
    }
    return ans;
}
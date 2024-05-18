#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>&arr, int target)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>>ans;
    for(int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum==target)
                {
                    ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                    k++;
                    l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }        
    }
    return ans;
}
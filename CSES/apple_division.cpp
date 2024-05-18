#include <bits/stdc++.h>
using namespace std;

// long long int minSubsetSumDifference(vector<long long int>& nums, long long int n)
// {
//     long long int sum = accumulate(nums.begin(),nums.end(),0);
//     vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
//     for (long long int i = 0; i < n ; i++)
//     {
//         dp[i][0] = true;
//     }    
//     if (nums[0]<=sum)
//     {
//         dp[0][nums[0]] = true;
//     }
//     for (long long int i = 1; i < n; i++)
//     {
//         for (long long int target = 0; target<=sum; target++)
//         {
//             bool take = false;
//             bool notake = dp[i-1][target];
//             if (nums[i]<=target) take = dp[i-1][target - nums[i]];
//             dp[i][target] = take || notake;
//         }
//     }
//     long long int _min = LONG_LONG_MAX;
//     long long int s1 = 0, s2 = sum;
//     for (long long int i = 0; i <= sum/2 ; i++)
//     {
//         if (dp[n-1][i])
//         {
//             s1 = i;
//             s2 = sum-i;
//             _min = min(_min,abs(s1-s2));
//         }
//     }
//     return _min;
// }

int main()
{
    long long int n;
    cin>>n;
    vector<long long int>v(n);
    for (long long int i = 0; i < n; i++) cin>>v[i];
    long long int sum = accumulate(v.begin(), v.end(), 0);
    long long int ans = LONG_LONG_MAX;
    for (int i = 0 ; i < (1<<n); i++)
    {
        long long int s = 0;
        for (int j = 0 ; j < n; j++)
        {
            if (i&(1<<j)){            
            //cout<<i<<" "<<(1<<j)<<" "<<j<<endl;
            s+=v[j];
            }
        }
        long long int curr = abs((sum - s) - s);
        ans = min(ans,curr);
    }
    cout<<ans<<endl;
    return 0;
}
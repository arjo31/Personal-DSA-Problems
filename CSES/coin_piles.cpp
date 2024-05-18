#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long int a,b;
        cin>>a>>b;
        cout << ((a + b) % 3 == 0 && (min(a, b) * 2 >= max(a, b)) ? "YES" : "NO") << endl;
        // if (a==0 && b==0)
        // {
        //     cout<<"YES"<<endl;
        //     continue;
        // }
        // if (a==0 || b==0)
        // {
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        // vector<vector<bool>>dp(a+1,vector<bool>(b+1,false));
        // if (a>=2 || b>=2)
        // {
        //     dp[1][2] = true;
        //     dp[2][1] = true;
        // }
        // for (long long int i = 3; i<=a; i++)
        // {
        //     for (long long int j = 3; j<=b; j++)
        //     {
        //         dp[i][j] = dp[i-1][j-2] || dp[i-2][j-1];
        //     }
        // }
        // cout<<((dp[a][b]) ? "YES" : "NO")<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int sum = 0;
    long long int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        long long int x;
        cin>>x;
        sum+=x;
        if (sum < 0)
        {
            ans = fmax(ans,sum);
            sum = 0;
            continue;
        }
        ans = fmax(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
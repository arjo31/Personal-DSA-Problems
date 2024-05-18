#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int capacity;
    cin >> capacity;

    vector<int> weights(n);

    for (int i = 0; i < n; i++)
        cin >> weights[i];

    vector<pair<int, int>> dp((1 << n));

    dp[0] = {1, 0}; //{no of rides/containers, no of people in last ride}

    for (int Set = 1; Set < (1 << n); Set++)
    {
        dp[Set] = {INT_MAX, INT_MAX};
        for (int i = 0; i < n; i++)
        {
            if ((1 << i) & Set)
            {
                int noOfRides = dp[Set ^ (1 << i)].first;
                int noOfPeopleInLastRide = dp[Set ^ (1 << i)].second;
                if (weights[i] + noOfPeopleInLastRide > capacity)
                {
                    noOfRides++;
                    dp[Set] = min(dp[Set], {noOfRides, weights[i]});
                }
                else
                {
                    dp[Set] = min(dp[Set], {noOfRides, weights[i] + noOfPeopleInLastRide});
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;

    return 0;
}
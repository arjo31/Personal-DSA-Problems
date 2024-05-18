#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int j = 1; j <= x; j++)
    {
        if (price[0] <= j)
            dp[0][j] = pages[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            int notPick = dp[i - 1][j];
            int pick = 0;
            if (price[i] <= j)
            {
                pick = pages[i] + dp[i - 1][j - price[i]];
            }
            dp[i][j] = max(pick, notPick);
        }
    }

    cout << dp[n - 1][x] << endl;
    return 0;
}

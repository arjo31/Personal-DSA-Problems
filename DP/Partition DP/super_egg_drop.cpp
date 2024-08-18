/*You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp{101, vector<int>(10001, -1)};

// Memoization : TC : O(k*n^2)
int superEggDrop(int k, int n)
{
    if (n == 1 || n == 0)
        return n;
    if (k == 1)
        return n;
    if (dp[k][n] != -1)
        return dp[k][n];
    int minDrops = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        int eggBreaks = superEggDrop(k - 1, i - 1);
        int eggNoBreak = superEggDrop(k, n - i);
        int cost = 1 + max(eggBreaks, eggNoBreak);
        minDrops = min(minDrops, cost);
    }
    return dp[k][n] = minDrops;
}

// More Optimized : Memoization with binary search TC : O(k*n*logn)
int superEggDrop(int k, int n)
{
    if (n == 0 || n == 1)
        return n;
    if (k == 1)
        return n;
    if (dp[k][n] != -1)
        return dp[k][n];

    int low = 1, high = n, minDrops = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int eggBreaks = superEggDrop(k - 1, mid - 1);
        int eggNoBreak = superEggDrop(k, n - mid);
        int cost = 1 + max(eggBreaks, eggNoBreak);
        if (eggBreaks > eggNoBreak)
            high = mid - 1;
        else
            low = mid + 1;
        minDrops = min(minDrops, cost);
    }

    return dp[k][n] = minDrops;
}

// Tabulation
int dp2O(int k, int n)
{
    if (n == 1)
    {
        return 1;
    }

    vector<int> dp(k + 1, 1);

    for (int i = 2; i <= n; ++i)
    {
        for (int j = k; j >= 1; --j)
        {
            dp[j] = j == 1 ? i : dp[j - 1] + dp[j] + 1;
        }

        if (dp[k] >= n)
        {
            return i;
        }
    }

    return -1;
}
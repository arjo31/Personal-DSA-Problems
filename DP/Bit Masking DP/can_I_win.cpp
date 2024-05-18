/*In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.

Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.*/

#include <bits/stdc++.h>
using namespace std;

bool solve(int player, int mask, int score, int total, int m, vector<vector<int>> &dp)
{
    if (dp[player][mask] != -1)
        return dp[player][mask];
    for (int i = m - 1; i >= 0; i--)
    {
        int newMask = (mask ^ (1 << i));
        if (((1 << i) & newMask) == 0)
        {
            if (score + (m - i) >= total || solve(!player, newMask, score + (m - i), total, m, dp) == 0)
            {
                return dp[player][mask] = 1;
            }
        }
    }
    return dp[player][mask] = 0;
}
bool canIWin(int maxChoosableInteger, int desiredTotal)
{
    if ((maxChoosableInteger * (maxChoosableInteger + 1) / 2) < desiredTotal)
        return false;
    vector<vector<int>> dp(2, vector<int>((1 << maxChoosableInteger), -1));
    solve(0, (1 << maxChoosableInteger) - 1, 0, desiredTotal, maxChoosableInteger, dp);
    return dp[0][(1 << maxChoosableInteger) - 1];
}
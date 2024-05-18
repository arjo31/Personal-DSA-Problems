/*A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    sort(satisfaction.begin(), satisfaction.end());
    solve(0, 1, satisfaction, dp);
    return dp[0][1];
}

int solve(int ind, int time, vector<int> &satisfaction, vector<vector<int>> &dp)
{
    if (ind >= satisfaction.size())
        return 0;
    if (dp[ind][time] != -1)
        return dp[ind][time];

    int take = satisfaction[ind] * time + solve(ind + 1, time + 1, satisfaction, dp);
    int notTake = 0 + solve(ind + 1, time, satisfaction, dp);

    return dp[ind][time] = max(take, notTake);
}

// Tabulation
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
    sort(satisfaction.begin(), satisfaction.end());
    for (int i = 1; i <= n + 1; i++)
        dp[n][i] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            int take = satisfaction[i] * (j) + dp[i + 1][j + 1];
            int notTake = 0 + dp[i + 1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[0][1];
}

// Greedy
int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();
    int cnt = 1;
    vector<int> time;
    for (int i = 0; i < n; i++)
    {
        time.push_back(cnt);
        cnt++;
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            if (time[j] < 0)
                return maxi;
            sum += time[j] * satisfaction[j];
        }

        maxi = max(maxi, sum);

        for (int k = i; k < n; k++)
        {
            time[k] -= 1;
        }
    }

    return maxi;
}
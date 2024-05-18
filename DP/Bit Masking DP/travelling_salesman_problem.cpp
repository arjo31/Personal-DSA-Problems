// Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city.

// Held - Karp Algorithm

#include <bits/stdc++.h>
using namespace std;

int dp[21][1 << 21];
int dist[21][21];

int tsp(int i, int S, int n)
{
    if (!(S ^ (1 << 0)))
        return dist[i][0];
    int ans = INT_MAX;
    if (dp[i][S] != -1)
        return dp[i][S];

    for (int j = 0; j < n; j++)
    {
        if ((S & (1 << j)) && j != i && j != 0 && dist[j][i] != 0)
        {
            ans = min(ans, dist[j][i] + tsp(j, (S ^ (1 << j)), n));
        }
    }
    return dp[i][S] = ans;
}

int main()
{
    int n;
    cin >> n;
    cout << "Enter the weights : "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, (1 << n) - 1, n) << endl;

    return 0;
}
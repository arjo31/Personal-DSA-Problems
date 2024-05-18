/*Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.*/

#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxLength = 0;
    for (int i = 0; i < n; i++)
        if (matrix[i][0] == '1')
        {
            dp[i][0] = 1;
            maxLength = 1;
        }
    for (int j = 0; j < m; j++)
        if (matrix[0][j] == '1')
        {
            dp[0][j] = 1;
            maxLength = 1;
        }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                dp[i][j] =
                    1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
            maxLength = max(maxLength, dp[i][j]);
        }
    }
    return maxLength * maxLength;
}
/*You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
    p.push({0, {0, 0}});
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    while (!p.empty())
    {
        int diff = p.top().first;
        int r = p.top().second.first;
        int c = p.top().second.second;

        p.pop();

        if (r == n - 1 && c == m - 1)
        {
            return diff;
        }

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if ((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m))
            {
                int newEffort = max(abs(heights[r][c] - heights[nrow][ncol]), diff);
                if (newEffort < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = newEffort;
                    p.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }
    return 0;
}
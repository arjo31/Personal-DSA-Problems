/*You are given a 2D array points and a string s where, points[i] represents the coordinates of point i, and s[i] represents the tag of point i.

A valid square is a square centered at the origin (0, 0), has edges parallel to the axes, and does not contain two points with the same tag.

Return the maximum number of points contained in a valid square.

Note:

A point is considered to be inside the square if it lies on or within the square's boundaries.
The side length of the square can be zero.
 */

#include <bits/stdc++.h>
using namespace std;

int maxPointsInsideSquare(vector<vector<int>> &points, string s)
{
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        points[i][0] = abs(points[i][0]);
        points[i][1] = abs(points[i][1]);
    }
    int l = 0;
    int r = 1e9;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        unordered_map<char, int> mpp;
        int f = 1;
        for (int i = 0; i < n; i++)
        {
            if (points[i][0] <= mid && points[i][1] <= mid)
            {
                mpp[s[i]]++;
            }
        }
        for (auto it : mpp)
        {
            if (it.second > 1)
                f = 0;
        }
        if (f)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (points[i][0] <= ans && points[i][1] <= ans)
        {
            count++;
        }
    }
    return count;
}
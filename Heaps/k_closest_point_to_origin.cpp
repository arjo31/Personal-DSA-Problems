/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).*/

#include <bits/stdc++.h>
using namespace std;

double dist(int x, int y)
{
    return sqrt(x * x + y * y);
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> p;
    for (auto it : points)
    {
        int x = it[0];
        int y = it[1];
        p.push({dist(x, y), {x, y}});
    }
    vector<vector<int>> ans;
    while (k--)
    {
        int x = p.top().second.first;
        int y = p.top().second.second;
        p.pop();

        ans.push_back({x, y});
    }
    return ans;
}
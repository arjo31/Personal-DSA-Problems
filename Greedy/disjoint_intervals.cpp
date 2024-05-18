/*Given a list of intervals [start, end]. Find the length of the maximal set of mutually disjoint intervals*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//Sort by early ending time
struct points
{
    int x;
    int y;
};

bool comp(struct points a, points b)
{
    return (a.y < b.y);
}

int maxDisjointIntervals(vector<vector<int>>&coordinates)
{
    int n = coordinates.size();
    struct points point[n];
    for (int i = 0; i < n; i++)
    {
        point[i].x = coordinates[i][0];
        point[i].y = coordinates[i][1];
    }
    sort(point, point + n, comp);
    int count = 1;
    int prev = point[0].y;
    for (int i = 1 ; i < n; i++)
    {
        if (point[i].x > prev)
        {
            count++;
            prev = point[i].y;
        }
    }
    return count;
}
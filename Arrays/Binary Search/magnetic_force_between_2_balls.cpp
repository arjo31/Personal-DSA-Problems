/*In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.*/

/*Aggressive cows method*/

#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int> &position, int m)
{
    sort(position.begin(), position.end());
    int n = position.size();
    int low = 1;
    int high = position[n - 1] - position[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(position, mid, m))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

bool isPossible(vector<int> &position, int mid, int m)
{
    int balls = 1;
    int initDist = position[0];
    int n = position.size();
    for (int i = 1; i < n; i++)
    {
        if (position[i] - initDist >= mid)
        {
            balls++;
            initDist = position[i];
        }
    }
    return (balls >= m);
}
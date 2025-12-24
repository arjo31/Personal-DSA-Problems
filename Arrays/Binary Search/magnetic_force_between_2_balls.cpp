/*In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.*/

/*Aggressive cows method*/

#include <bits/stdc++.h>
using namespace std;

int n;

int noOfBalls(vector<int> &positions, int force)
{
    int initPos = positions[0];
    int balls = 1;
    for (int i = 1; i < n; i++)
    {
        if (positions[i] - initPos >= force)
        {
            balls += 1;
            initPos = positions[i];
        }
    }
    return balls;
}

int maxDistance(vector<int> &positions, int m)
{
    n = positions.size();
    sort(begin(positions), end(positions));
    int minForce = 1;
    int maxForce = positions[n - 1] - positions[0];
    int minMaxForce = maxForce;
    while (minForce <= maxForce)
    {
        int midForce = minForce + (maxForce - minForce) / 2;
        if (noOfBalls(positions, midForce) < m)
        {
            maxForce = midForce - 1;
        }
        else
        {
            minMaxForce = midForce;
            minForce = midForce + 1;
        }
    }
    return minMaxForce;
}
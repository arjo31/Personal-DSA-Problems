/*N children are standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum number of candies you must give?*/

#include <bits/stdc++.h>
using namespace std;

int countCandies(vector<int>&rating)
{
    int n = rating.size();
    vector<int>candies(n);
    for (int i = 0; i < n; i++) candies[i] = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (rating[i+1] > rating[i])
        {
            candies[i+1] = candies[i] + 1;
        }
    }
    for (int i = n-2; i >= 0; i--)
    {
        if (rating[i] > rating[i+1] && candies[i] <= candies[i+1])
        {
            candies[i] = candies[i+1] + 1;
        }
    }
    return accumulate(candies.begin(), candies.end(), 0);
}
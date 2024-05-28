/*There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.*/

#include <bits/stdc++.h>
using namespace std;

// TC - O(3n) and SC - O(2n)
int candy(vector<int> &rating)
{
    int n = rating.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (rating[i + 1] > rating[i])
            left[i + 1] = left[i] + 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (rating[i] > rating[i + 1])
            right[i] = right[i + 1] + 1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += max(left[i], right[i]);
    }
    return sum;
}

// TC : O(3*N) and SC : O(N)
int candy(vector<int> &rating)
{
    int n = rating.size();
    vector<int> candies(n, 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (rating[i + 1] > rating[i])
        {
            candies[i + 1] = candies[i] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (rating[i] > rating[i + 1] && candies[i] <= candies[i + 1])
        {
            candies[i] = candies[i + 1] + 1;
        }
    }
    return accumulate(candies.begin(), candies.end(), 0);
}

//TC : O(n) and Sc : O(1)
int candy(vector<int>&rating)
{
    int n = rating.size();
    int i = 1;
    int sum = 1;
    while (i < n)
    {
        if (rating[i]==rating[i - 1])
        {
            sum+=1;
            i++;
        }
        int peak = 1;
        while (i < n && rating[i] > rating[i - 1])
        {
            peak++;
            sum+=peak;
            i++;
        }
        int down = 1;
        while (i < n && rating [i - 1] > rating[i])
        {
            sum+=down;
            down++;
            i++;
        }
        if (down > peak) sum = sum + (down - peak);
    }
    return sum;
}
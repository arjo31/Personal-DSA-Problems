/*You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.*/
#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int n = people.size();
    int boats = n;
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int sum = people[i] + people[j];
        if (sum <= limit)
        {
            boats--;
            i++;
            j--;
        }
        else if (sum > limit)
        {
            j--;
        }
    }
    return boats;
}
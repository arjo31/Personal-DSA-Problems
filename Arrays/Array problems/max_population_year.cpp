/*You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.

Constraints:

1 <= logs.length <= 100
1950 <= birthi < deathi <= 2050
*/

#include <bits/stdc++.h>
using namespace std;

// Line Sweep -> O(n log n)
int maximumPopulation(vector<vector<int>> &logs)
{
    int n = logs.size();
    vector<pair<int, int>> events;
    for (auto log : logs)
    {
        events.push_back({log[0], 1});
        events.push_back({log[1], -1});
    }

    sort(events.begin(), events.end());

    int earliestYear = events[0].first;
    int maxPop = 1;
    int pop = 1;
    for (int i = 1; i < 2 * n; i++)
    {
        pop += events[i].second;
        if (pop > maxPop)
        {
            earliestYear = events[i].first;
            maxPop = pop;
        }
    }
    return earliestYear;
}

// Difference Array Technique -> O(n+d)
int maximumPopulation(vector<vector<int>> &logs)
{
    int n = logs.size();
    vector<int> diff(2051, 0);
    for (auto log : logs)
    {
        diff[log[0]] += 1;
        diff[log[1]] -= 1;
    }
    int maxPop = 0, maxYear = 1950, currentPop = 0;
    for (int i = 1950; i <= 2050; i++)
    {
        currentPop += diff[i];
        if (currentPop > maxPop)
        {
            maxPop = currentPop;
            maxYear = i;
        }
    }
    return maxYear;
}
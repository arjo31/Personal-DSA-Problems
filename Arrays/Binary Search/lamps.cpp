/*Given n houses and M lamps on a number line, each at unique position, find the minimum value of k such that every house receives light from at least one lamp within distance of k units*/

#include <bits/stdc++.h>
using namespace std;

int canIlluminate(vector<int> &houses, vector<int> &lamps, int mid)
{
    int i = 0;
    int j = 0;
    int n = houses.size();
    int m = lamps.size();
    while (i < n && j < m)
    {
        if (abs(houses[i] - lamps[j]) <= mid)
            i++;
        else
            j++;
    }
    return (i == n);
}

int findMinimumK(vector<int> &houses, vector<int> &lamps)
{
    sort(houses.begin(), houses.end());
    sort(lamps.begin(), lamps.end());
    int n = houses.size();
    int m = lamps.size();
    int low = 0;
    int high = max(*max_element(houses.begin(), houses.end()) - *min_element(lamps.begin(), lamps.end()), *max_element(lamps.begin(), lamps.end()) - *min_element(houses.begin(), houses.end()));
    int result = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canIlluminate(houses, lamps, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return result;
}
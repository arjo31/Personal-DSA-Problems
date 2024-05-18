/*Given N bulbs, either on (1) or off (0). Turning on ith bulb causes all remaining bulbs on right to flip. Find the minimum number of switches to turn all the bulbs on*/

#include <bits/stdc++.h>
using namespace std;

int bulbs(vector<int>&arr)
{
    int n = arr.size();
    int cost = 0;
    for(auto bit : arr)
    {
        if (cost%2==0) bit = bit;
        else bit = !bit;

        if (bit%2==1) continue;
        else cost++;
    }
    return cost;
}
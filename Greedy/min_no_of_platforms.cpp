#include <bits/stdc++.h>
using namespace std;

/*Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

*/

void solve(vector<int> arrivals, vector<int> departures, int n)
{
    multiset<pair<int, char> > order;
    for (int i = 0; i < n; i++) {
        order.insert(make_pair(arrivals[i], 'a'));
        order.insert(make_pair(departures[i], 'd'));
    }
 
    int result = 0;
    int plat_needed = 0;
 
    for (auto it : order) {
        if (it.second == 'a')
            plat_needed++;
        else
            plat_needed--;
 
        if (plat_needed > result)
            result = plat_needed;
    }
    cout<<result<<endl;
}


int main()
{
    vector<int>start = {900, 940, 950, 1100, 1500, 1800};
    vector<int>end   = {910, 1200, 1120, 1130, 1900, 2000};
    solve(start,end,6);
    return 0;
}
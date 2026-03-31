/*You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.*/

#include <bits/stdc++.h>
using namespace std;

// Line sweep
vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> freq(n, 0);
    for (auto booking : bookings)
    {
        int flightA = booking[0] - 1;
        int flightB = booking[1] - 1;
        freq[flightA] += booking[2];
        ;
        ;
        if (flightB + 1 < n)
            freq[flightB + 1] -= booking[2];
    }
    for (int i = 1; i < n; i++)
    {
        freq[i] = freq[i - 1] + freq[i];
    }
    return freq;
}
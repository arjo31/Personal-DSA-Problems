/*A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

You are given some events [startTime, endTime), after each given event, return an integer k representing the maximum k-booking between all the previous events.

Implement the MyCalendarThree class:

MyCalendarThree() Initializes the object.
int book(int startTime, int endTime) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.*/

#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree
{
public:
    map<int, int> mpp;
    MyCalendarThree() {}

    int book(int startTime, int endTime)
    {
        mpp[startTime]++;
        mpp[endTime]--;
        int bookTime = 0;
        int maxTime = 0;
        for (auto it : mpp)
        {
            bookTime += it.second;
            maxTime = max(maxTime, bookTime);
        }
        return maxTime;
    }
};
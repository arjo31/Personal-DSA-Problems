/*You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.*/

#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
public:
    map<int, int> mpp;
    MyCalendar() {}

    bool book(int startTime, int endTime)
    {
        mpp[startTime]++;
        mpp[endTime]--;
        int bookTime = 0;
        for (auto it : mpp)
        {
            bookTime += it.second;

            if (bookTime >= 2)
            {
                mpp[startTime]--;
                mpp[endTime]++;

                if (mpp[startTime] == 0)
                    mpp.erase(startTime);
                if (mpp[endTime] == 0)
                    mpp.erase(endTime);

                return false;
            }
        }
        return true;
    }
};
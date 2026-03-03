/*You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

Implement the MyCalendarTwo class:

MyCalendarTwo() Initializes the calendar object.
boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.*/

#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo
{
public:
    map<int, int> events;
    MyCalendarTwo() {}

    bool book(int startTime, int endTime)
    {
        events[startTime]++;
        events[endTime]--;

        int bookings = 0;
        for (auto booking : events)
        {
            bookings += booking.second;

            if (bookings >= 3)
            {
                events[startTime]--;
                events[endTime]++;

                if (events[startTime] == 0)
                    events.erase(startTime);
                if (events[endTime] == 0)
                    events.erase(endTime);
                return false;
            }
        }
        return true;
    }
};
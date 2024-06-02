/*You are given a string s. Simulate events at each second i:

If s[i] == 'E', a person enters the waiting room and takes one of the chairs in it.
If s[i] == 'L', a person leaves the waiting room, freeing up a chair.
Return the minimum number of chairs needed so that a chair is available for every person who enters the waiting room given that it is initially empty.*/

#include <bits/stdc++.h>
using namespace std;

int minimumChairs(string s)
{
    int minChairs = INT_MIN;
    int chairs = 0;
    for (char c : s)
    {
        if (c == 'E')
        {
            chairs++;
        }
        else
            chairs--;
        minChairs = max(minChairs, chairs);
    }
    return minChairs;
}
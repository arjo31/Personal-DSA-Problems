/*We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size();
    list<int> st;
    for (int i = 0; i < n; i++)
    {
        int x = asteroids[i];
        if (x > 0)
            st.push_back(x);
        else
        {
            while (!st.empty() && st.back() > 0 && st.back() < abs(x))
                st.pop_back();

            if (!st.empty() && st.back() == abs(x))
                st.pop_back();
            else if (st.empty() or st.back() < 0)
                st.push_back(x);
        }
    }
    vector<int> ans(st.begin(), st.end());
    return ans;
}
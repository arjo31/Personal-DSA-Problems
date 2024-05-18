/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;
    int n = temperatures.size();
    st.push(0);
    vector<int> temp(n);
    for (int i = 1; i < n; i++)
    {
        if (st.empty())
        {
            st.push(i);
            continue;
        }

        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            temp[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        temp[st.top()] = 0;
        st.pop();
    }
    return temp;
}
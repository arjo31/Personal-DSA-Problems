/*Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

There is one laser beam between any two security devices if both conditions are met:

The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.*/

#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string> &bank)
{
    int n = bank.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        string s = bank[i];
        int count = 0;
        for (char c : s)
        {
            if (c == '1')
                count++;
        }
        if (count)
            st.push(count);
    }
    if (st.size() <= 1)
        return 0;
    int ans = 0;
    int c1 = st.top();
    st.pop();
    int c2 = st.top();
    ans += c1 * c2;
    st.pop();
    c1 = c2;
    while (!st.empty())
    {
        c2 = st.top();
        st.pop();
        ans += c1 * c2;
        c1 = c2;
    }
    return ans;
}

// Even simpler approach

int numberOfBeams(vector<string> &bank)
{
    int n = bank.size();
    int ans = 0;
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        string s = bank[i];
        int count = 0;
        for (char c : s)
            if (c == '1')
                count++;
        if (count > 0)
        {
            ans += count * prev;
            prev = count;
        }
    }
    return ans;
}
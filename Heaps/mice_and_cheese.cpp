/*There are two mice and n different types of cheese, each type of cheese should be eaten by exactly one mouse.

A point of the cheese with index i (0-indexed) is:

reward1[i] if the first mouse eats it.
reward2[i] if the second mouse eats it.
You are given a positive integer array reward1, a positive integer array reward2, and a non-negative integer k.

Return the maximum points the mice can achieve if the first mouse eats exactly k types of cheese.*/

#include <bits/stdc++.h>
using namespace std;

int miceAndCheese(vector<int> &r1, vector<int> &r2, int k)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    int n = r1.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        pq.push({r1[i] - r2[i], {r1[i], i}});
    }
    int ans = 0;

    while (k && !pq.empty())
    {
        ans += pq.top().second.first;
        st.insert(pq.top().second.second);
        pq.pop();
        k--;
    }

    for (int i = 0; i < n; i++)
    {
        if (!st.count(i))
        {
            ans += r2[i];
        }
    }
    return ans;
}
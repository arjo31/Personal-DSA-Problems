/*You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.*/

#include <bits/stdc++.h>
using namespace std;

int fillCups(vector<int> &amount)
{
    priority_queue<int> pq;
    for (int i : amount)
        pq.push(i);
    int count = 0;
    while (pq.top() != 0)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        a--;
        b--;
        pq.push(a);
        pq.push(b);
        count++;
    }
    return count;
}
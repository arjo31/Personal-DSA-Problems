/*You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.*/

#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> p;
    for (int i : stones)
        p.push(i);
    while (!p.empty() && p.size() != 1)
    {
        int heavy = p.top();
        p.pop();
        int secondHeavy = p.top();
        p.pop();
        if (heavy == secondHeavy)
            continue;
        else
            p.push(abs(heavy - secondHeavy));
    }
    return p.empty() ? 0 : p.top();
}
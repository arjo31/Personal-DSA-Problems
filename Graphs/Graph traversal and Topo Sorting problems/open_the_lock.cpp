/*You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.*/

#include <bits/stdc++.h>
using namespace std;

int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> s(deadends.begin(), deadends.end());
    if (s.find("0000") != s.end())
        return -1;

    queue<pair<string, int>> q;
    q.push({"0000", 0});
    unordered_set<string> visited;
    visited.insert("0000");
    while (!q.empty())
    {
        string src = q.front().first;
        int count = q.front().second;
        q.pop();

        if (src == target)
            return count;

        for (int i = 0; i < 4; i++)
        {
            for (int j : {-1, 1})
            {
                int newDigit = (src[i] - '0' + j + 10) % 10;
                string adjString = src;
                adjString[i] = newDigit + '0';

                if (visited.find(adjString) == visited.end() && s.find(adjString) == s.end())
                {
                    q.push({adjString, count + 1});
                    visited.insert(adjString);
                }
            }
        }
    }
    return -1;
}
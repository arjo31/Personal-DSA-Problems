/*You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.*/

#include <bits/stdc++.h>
using namespace std;

// Priority Queue
int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> mpp;
    for (char c : tasks)
    {
        mpp[c]++;
    }
    priority_queue<int> p;
    for (auto it : mpp)
    {
        p.push(it.second);
    }
    int result = 0;
    while (!p.empty())
    {
        int cycles = n + 1;
        vector<int> temp;
        int time = 0;
        while (cycles && !p.empty())
        {
            int countLeft = p.top() - 1;
            p.pop();
            temp.push_back(countLeft);
            time++;
            cycles--;
        }

        for (int i : temp)
        {
            if (i)
                p.push(i);
        }
        result += (p.empty()) ? time : (n + 1);
    }
    return result;
}

// Greedy
int leastInterval(vector<char> &tasks, int n)
{
    vector<int> freq(26, 0);
    for (char c : tasks)
    {
        freq[c - 'A']++;
    }
    sort(freq.begin(), freq.end());
    int maxGapsPossible = freq[25] - 1;
    int idleSpaces = maxGapsPossible * n;

    for (int i = 24; i >= 0; i--)
    {
        idleSpaces -= min(maxGapsPossible, freq[i]);
    }
    return (idleSpaces > 0) ? idleSpaces + tasks.size() : tasks.size();
}
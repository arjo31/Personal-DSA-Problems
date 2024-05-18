// You are given an array apple of size n and an array capacity of size m.

// There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

// Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

// Note that, apples from the same pack can be distributed into different boxes.

#include <bits/stdc++.h>
using namespace std;

int minimumBoxes(vector<int> &apple, vector<int> &capacity)
{
    int n = apple.size();
    int m = capacity.size();
    int count = 0;
    int sum = accumulate(apple.begin(), apple.end(), 0);
    sort(capacity.rbegin(), capacity.rend());
    for (int i = 0; i < m; i++)
    {
        sum = sum - capacity[i];
        count++;
        if (sum <= 0)
            break;
    }
    return count;
}
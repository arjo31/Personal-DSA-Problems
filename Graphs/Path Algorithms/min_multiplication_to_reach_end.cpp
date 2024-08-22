/*Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.*/

#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> arr, int start, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> vis(10000, 0);
    vis[start] = 1;
    int n = arr.size();
    q.push({0, start});
    while (!q.empty())
    {
        int way = q.top().first;
        int num = q.top().second;
        q.pop();

        if (num == end)
            return way;

        for (int i = 0; i < n; i++)
        {
            int _n = (num * arr[i]) % 100000;
            if (!vis[_n])
            {
                q.push({way + 1, _n});
                vis[_n] = 1;
            }
        }
    }
    return -1;
}

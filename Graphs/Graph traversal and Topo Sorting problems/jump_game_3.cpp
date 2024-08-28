/*Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.*/

#include <bits/stdc++.h>
using namespace std;

bool canReach(vector<int> &arr, int start)
{
    queue<int> q;
    q.push(start);
    vector<int> vis(arr.size());
    vis[start] = 1;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        if (arr[i] == 0)
            return true;

        int right = i + arr[i];
        int left = i - arr[i];

        if (right < arr.size() && !vis[right])
        {
            q.push(right);
            vis[right] = 1;
        }
        if (left >= 0 && !vis[left])
        {
            q.push(left);
            vis[left] = 1;
        }
    }
    return false;
}
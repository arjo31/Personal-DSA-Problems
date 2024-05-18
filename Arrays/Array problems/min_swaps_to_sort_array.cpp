/*Given an array of N distinct elements, find the minimum number of swaps required to sort the array.*/

#include <bits/stdc++.h>
using namespace std;

// O(n log n)
int minSwaps(vector<int> &arr)
{
    int n = arr.size();
    pair<int, int> p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].first = arr[i];
        p[i].second = i;
    }

    sort(p, p + n);

    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || p[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            j = p[i].second;
            cycle_size++;
        }

        if (cycle_size > 0)
            ans += (cycle_size - 1);
    }
    return ans;
}

// O(n^2)
void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int indexOf(vector<int> &arr, int ele)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

int minSwaps(vector<int> arr, int N)
{
    int ans = 0;
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());

    for (int i = 0; i < N; i++)
    {
        if (arr[i] != temp[i])
        {
            ans++;
            swap(arr, i, indexOf(arr, temp[i]));
        }
    }
    return ans;
}
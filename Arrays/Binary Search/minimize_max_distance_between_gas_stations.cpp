/*You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. You have to place ‘k’ new gas stations on the X-axis. You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. Let ‘dist’ be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
Find the minimum value of ‘dist’.

Note: Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer is 0.65421678124, it is okay to return 0.654216. Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.*/

#include <bits/stdc++.h>
using namespace std;

//Priority Queue
long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;

        long double inidiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}

//Binary Search
int numberOfGasStationsRequired(long double dist, vector<int> &arr)
{
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6 ;
    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}
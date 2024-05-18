#include <bits/stdc++.h>
using namespace std;

//Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

vector<pair<int,int>> allPairs(vector<int>&a, vector<int>&b, int x)
{
    int n = a.size();
    int m = b.size();
    vector<pair<int,int>>ans;

    int i = 0;
    int j = m - 1;

    while (i < n && j>=0)
    {
        int sum = a[i] + b[j];
        if (sum==x)
        {
            ans.push_back({a[i],b[j]});
            i++;
            j--;
        }
        else if (sum > x) j--;
        else i++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
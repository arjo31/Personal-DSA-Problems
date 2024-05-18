#include <bits/stdc++.h>
using namespace std;

int mice(vector<int>&mice, vector<int>&holes)
{
    sort(mice.begin(), mice.end());
    sort(holes.begin(), holes.end());

    int ans = 0;
    int n = mice.size();
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, abs(mice[i] - holes[i]));
    }
    return ans;
}
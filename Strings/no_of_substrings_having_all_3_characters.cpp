/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.*/

#include <bits/stdc++.h>
using namespace std;

// First Approach
int numberOfSubstrings(string s)
{
    int ans = 0;
    int l = 0;
    int r = 0;
    int n = s.size();
    vector<int> occ({0, 0, 0});
    for (r = 0; r < n; r++)
    {
        occ[s[r] - 'a']++;
        while (occ[0] && occ[1] && occ[2])
        {
            ans += n - r;
            occ[s[l] - 'a']--;
            l++;
        }
    }
    return ans;
}

// Second Approach
int numberOfSubstrings(string s)
{
    int ans = 0;
    int l = 0;
    int r = 0;
    int n = s.size();
    vector<int> lastSeen({-1, -1, -1});
    for (r = 0; r < n; r++)
    {
        lastSeen[s[r] - 'a'] = r;

        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            ans += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }
    }
    return ans;
}
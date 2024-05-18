/*In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.

Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character key[i]:

You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the "12:00" direction, where this character must equal key[i].
If the character key[i] has been aligned at the "12:00" direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.*/

#include <bits/stdc++.h>
using namespace std;
int ring_size;
unordered_map<char, vector<int>> mp;
int clockwise(int curr, int new_pos)
{
    if (new_pos >= curr)
    {
        return new_pos - curr;
    }
    return ring_size - (curr - new_pos);
}
int anti_clockwise(int curr, int new_pos)
{
    if (curr >= new_pos)
    {
        return curr - new_pos;
    }
    return ring_size - (new_pos - curr);
}
int solve(string &key, int idx, int pos, vector<vector<int>> &dp)
{
    if (idx == key.size())
    {
        return 0; // end of key
    }
    if (dp[idx][pos] != -1)
    {
        return dp[idx][pos];
    }
    int steps = INT_MAX;
    int key_value = key[idx];

    // going to all indexes
    for (int i = 0; i < mp[key_value].size(); i++)
    {
        int new_pos = mp[key_value][i];
        int taken = solve(key, idx + 1, new_pos, dp);
        // clockwise
        steps = min(steps, 1 + clockwise(pos, new_pos) + taken);
        // anticlockwise
        steps = min(steps, 1 + anti_clockwise(pos, new_pos) + taken);
    }
    return dp[idx][pos] = steps;
}

int findRotateSteps(string &ring, string &key)
{
    ring_size = ring.size();
    for (int i = 0; i < ring_size; i++)
    {
        mp[ring[i]].push_back(i);
    }

    vector<vector<int>> dp(key.size(), vector<int>(ring.size(), -1));
    return solve(key, 0, 0, dp);
}
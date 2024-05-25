/*You are given an array nums, where each number in the array appears either once or twice.

Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.*/

#include <bits/stdc++.h>
using namespace std;

int duplicateNumbersXOR(vector<int> &nums)
{
    set<int> s;
    int _xor = 0;
    for (int i : nums)
    {
        if (s.count(i))
        {
            _xor = _xor ^ i;
        }
        else
            s.insert(i);
    }
    return _xor;
}
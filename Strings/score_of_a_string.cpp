/*You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

Return the score of s.*/
#include <bits/stdc++.h>
using namespace std;

int scoreOfString(string s)
{
    int sum = 0;
    for (int i = 1; i < s.size(); i++)
    {
        sum += abs((s[i] - 'a') - (s[i - 1] - 'a'));
    }
    return sum;
}
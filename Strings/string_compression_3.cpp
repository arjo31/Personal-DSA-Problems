/*Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:

Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.

Return the string comp.*/

#include <bits/stdc++.h>
using namespace std;

string compressedString(string word)
{
    string comp = "";
    unordered_map<char, int> mpp;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        char c = word[i];
        if (mpp.empty())
        {
            mpp[c]++;
            continue;
        }
        char prevChar = word[i - 1];
        if (mpp.find(c) == mpp.end())
        {
            comp += to_string(mpp[prevChar]) + prevChar;
            mpp[c]++;
            mpp.erase(prevChar);
        }
        else if (mpp[c] < 9)
            mpp[c]++;
        else if (mpp[c] >= 9)
        {
            comp += to_string(mpp[c]) + c;
            mpp[c] = 1;
        }
    }
    char prevChar = word[n - 1];
    comp += to_string(mpp[prevChar]) + prevChar;
    return comp;
}
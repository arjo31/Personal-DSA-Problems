/*A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.*/

#include <bits/stdc++.h>
using namespace std;

int minMutation(string startGene, string endGene, vector<string> &bank)
{
    queue<pair<string, int>> q;
    q.push({startGene, 0});
    unordered_set<string> vis;
    vis.insert(startGene);
    unordered_set<string> wordBank(bank.begin(), bank.end());
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endGene)
            return steps;
        for (int i = 0; i < 8; i++)
        {
            char ogCh = word[i];
            vector<char> letters = {'A', 'C', 'G', 'T'};
            for (int j = 0; j < 4; j++)
            {
                if (ogCh != letters[j])
                {
                    word[i] = letters[j];
                    if (vis.find(word) == vis.end() && wordBank.find(word) != wordBank.end())
                    {
                        vis.insert(word);
                        q.push({word, steps + 1});
                    }
                }
            }
            word[i] = ogCh;
        }
    }
    return -1;
}
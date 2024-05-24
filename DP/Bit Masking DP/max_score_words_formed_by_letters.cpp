/*Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(string word, unordered_map<char, int> mpp)
{
    for (char c : word)
    {
        if (mpp[c] == 0)
            return false;
        mpp[c]--;
    }
    return true;
}

int calculateScore(string word, unordered_map<char, int> &mpp, vector<int> &score)
{
    int point = 0;
    for (char c : word)
    {
        point += score[c - 'a'];
        mpp[c]--;
    }
    return point;
}

void recoverCount(string word, unordered_map<char, int> &mpp)
{
    for (char c : word)
        mpp[c]++;
}

int solve(int ind, int bitMask, unordered_map<char, int> &mpp, vector<string> &words, vector<int> &score, vector<vector<int>> &dp)
{
    if (ind >= words.size())
    {
        return 0;
    }
    if (dp[ind][bitMask] != -1)
        return dp[ind][bitMask];
    int maxScore = 0;
    for (int i = 0; i < words.size(); i++)
    {
        int newMask = (1 << i) ^ bitMask;
        if (bitMask & (1 << i))
        {
            string word = words[i];
            if (isPossible(word, mpp))
            {
                int sc = calculateScore(word, mpp, score);
                maxScore = max(maxScore, sc + solve(ind + 1, newMask, mpp, words, score, dp));
                recoverCount(word, mpp);
            }
        }
    }
    return dp[ind][bitMask] = maxScore;
}

int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
{
    int n = words.size();
    unordered_map<char, int> mpp;
    for (char c : letters)
        mpp[c]++;
    vector<vector<int>> dp(n + 1, vector<int>(1 << n, -1));
    return solve(0, (1 << n) - 1, mpp, words, score, dp);
}
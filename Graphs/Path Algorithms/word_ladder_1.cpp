/*Given are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.

In this problem statement, we need to keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
Note:  If there’s no possible way to transform the sequence from startWord to targetWord return 0.*/

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string start, string end, vector<string>&wordList)
{
    unordered_set<string>s(wordList.begin(),wordList.end());
    s.erase(start);
    queue<pair<string,int>>q;
    q.push({start,1});
    while(!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word==end) return steps;
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch<='z'; ch++)
            {
                word[i] = ch;
                if (s.find(word)!= s.end()) //Word found
                {
                    s.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}
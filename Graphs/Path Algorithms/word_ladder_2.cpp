/*A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findLadders(string start, string end, vector<string>& wordList)
{
    queue<vector<string>>q;
    unordered_set<string> st(wordList.begin(),wordList.end());
    q.push({start});
    vector<string>usedOnLevel;
    usedOnLevel.push_back(start);
    int level = 0;
    vector<vector<string>>ans;
    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();
        //Erase all words that has been used in the previous levels to transform
        if (vec.size() > level)
        {
            level++;
            for (auto it : usedOnLevel)
            {
                st.erase(it);
            }
            usedOnLevel.clear();
        }
        string word = vec.back();
        if (word==end)
        {
            if (ans.size()==0)
            {
                ans.push_back(vec);
            }
            else if(ans[0].size()==vec.size())
            {
                ans.push_back(vec);
            }
        }
        for (int i = 0 ; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch<='z'; ch++)
            {
                word[i] = ch;
                if (st.count(word) > 0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}
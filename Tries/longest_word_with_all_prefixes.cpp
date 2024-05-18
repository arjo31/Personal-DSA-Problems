#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *t)
    {
        links[ch - 'a'] = t;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->containsKey(word[i]))
            {
                temp->put(word[i], new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }

    bool checkIfPrefixExists(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->containsKey(word[i]))
            {
                temp = temp->get(word[i]);
                if (temp->isEnd() == false)
                    return false;
            }
            return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie trie;
    for (auto it : a)
    {
        trie.insert(it);
    }
    string longest = "";
    for (auto it : a)
    {
        if (trie.checkIfPrefixExists(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
        }
        else if (it.length() == longest.length() && it < longest)
        {
            longest = it;
        }
    }
    if (longest == "")
        return "None";
    return longest;
}
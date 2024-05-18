#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct node
{
    node* links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a']!=NULL);
    }

    void put(char ch, node* t)
    {
        links[ch - 'a'] = t;
    }

    node* get(char ch)
    {
        return links[ch - 'a'];
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
        node* root;
    public:
        Trie()
        {
            root = new node();
        }

        /*Inserts a word in the trie*/
        void insert(string word)
        {
            node* t = root;
            for (int i = 0; i < word.length(); i++)
            {
                if (!t->containsKey(word[i]))
                {
                    t->put(word[i], new node());
                }
                t = t->get(word[i]); //Move to reference trie
            }
            t->setEnd();
        }

        /*Returns true if word in trie*/
        bool search(string word)
        {
            node* temp = root;
            for (int i = 0 ; i < word.length(); i++)
            {
                if (!temp->containsKey(word[i])) return false;
                temp = temp->get(word[i]);
            }
            return temp->isEnd();
        }

        /*Return if there is any word in the trie that starts with a given prefix*/
        bool startsWith(string prefix)
        {
            node* node = root;
            for (int i = 0; i < prefix.length(); i++)
            {
                if (!node->containsKey(prefix[i])) return false;
                node = node->get(prefix[i]);
            }
            return true;
        }
};

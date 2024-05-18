#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Node
{
    Node* links[26];
    int countEndWith = 0;
    int countPrefix = 0;
    bool containsKey(char ch)
    {
        return (links[ch - 'a']!=NULL);
    }

    void put(char ch, Node* t)
    {
        links[ch - 'a'] = t;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    void increaseEnd()
    {
        countEndWith++;
    }

    void increasePrefix()
    {
        countPrefix++;
    }

    void reduceEnd()
    {
        countEndWith--;
    }

    void reducePrefix()
    {
        countPrefix--;
    }

    int getEnd()
    {
        return countEndWith;
    }

    int getPrefix()
    {
        return countPrefix;
    }
};

class Trie
{
    private:
        Node* root;
    public:
        Trie()
        {
            root = new Node();

        }

        /*Inserts a word in the trie*/
        void insert(string word)
        {
            Node* t = root;
            for (int i = 0; i < word.length(); i++)
            {
                if (!t->containsKey(word[i]))
                {
                    t->put(word[i], new Node());
                }
                t = t->get(word[i]); //Move to reference trie
                t->increasePrefix();
            }
            t->increaseEnd();
        }

        int countWordsEqualTo(string &word)
        {
            Node* node = root;
            for (int i = 0; i < word.length(); i++)
            {
                if (node->containsKey(word[i])) node = node->get(word[i]);
                else return 0;
            }
            return node->getEnd();
        }

        int countWordsStartingWith(string &word)
        {
            Node* node = root;
            for (int i = 0; i < word.length(); i++)
            {
                if (node->containsKey(word[i])) node = node->get(word[i]);
                else return 0;
            }
            return node->getPrefix();
        }

        void erase(string &word)
        {
            Node* node = root;
            for (int i = 0; i < word.size(); i++)
            {
                if (node->containsKey(word[i]))
                {
                    node = node->get(word[i]);
                    node->reducePrefix();
                }
                else
                {
                    return;
                }
            }
            node->reduceEnd();
        }
};
 
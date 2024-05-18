#include <bits/stdc++.h>
using namespace std;

//Aho Corasick Algorithm
const int MOD = 1e9 + 7;

struct node
{
    struct node* links[26];
    bool flag = false;

    void putKey(char ch, struct node* t)
    {
        links[ch - 'a'] = t;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a']!=NULL;
    }

    struct node* getKey(char ch)
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
    public:
        struct node* root;
        Trie()
        {
            root = new node();
        }
        void insertString(string s)
        {
            struct node* t = root;
            for (auto ch : s)
            {
                if (!t->containsKey(ch))
                {
                    t->putKey(ch, new node());
                }
                t = t->getKey(ch);
            }
            t->setEnd();
        }

        bool searchString(string s)
        {
            struct node* t = root;
            for (auto ch : s)
            {
                if (!t->containsKey(ch)) return false;
                t = t->getKey(ch);
            }
            return t->isEnd();
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int t;
    cin>>t;
    Trie trie;
    while (t--)
    {
        string a;
        cin>>a;
        trie.insertString(a);
    }
    int n = s.size();
    vector<int>dp(n+1);
    dp[n] = 1;

    for (int i = n - 1; i>=0; i--)
    {
        node* temp = trie.root;
        for (int j = i; j < n; j++)
        {
            if (!temp->containsKey(s[j])) break;
            temp = temp->getKey(s[j]);
            if (temp->isEnd())
            {
                dp[i] = dp[i]%MOD + dp[j+1]%MOD;
                dp[i] = dp[i]%MOD;
            }
        } 
    }
    cout<<dp[0]<<endl;
    return 0;
}
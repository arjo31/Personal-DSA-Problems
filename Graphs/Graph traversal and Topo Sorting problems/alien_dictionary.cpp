#include <bits/stdc++.h>
using namespace std;

void alienDictionary(vector<string>&dictionary, int k)
{
    vector<int>adj[k];
    int n = dictionary.size();
    for (int i = 0; i < n-1 ; i++)
    {
        string a = dictionary[i];
        string b = dictionary[i+1];
        int len = min(a.size(),b.size());
        for (int ptr = 0; ptr < len ;ptr++)
        {
            if (a[ptr]!=b[ptr])
            {
                adj[a[ptr] - 'a'].push_back(b[ptr] - 'a');
                break;
            }
        }
    }
    int indegree[k] = {0};
    queue<int>q;
    for (int i = 0; i < k ; i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < k ;i++)
    {
        if (indegree[i]==0) q.push(i);
    }
    vector<int>ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it]==0) q.push(it);
        }
    }
    if (ans.empty()) cout<<"Empty"<<endl;
    string s = "";
    for (auto it : ans)
    {
        s = s + char(it+'a');
    }
    cout<<s<<endl;
}

int main()
{
    vector<string> dictionary = {"abdd", "bebeceaedcaabaaeeadbabedabcecbbdaebbabbdeaceebddd", "adadeddaecdecbcbbbcadddaaecbdecaacdbeecbabcd", "cabbecbc", "a", "cceadabecbbcaeadaeceebcb", "cdbccbdcaccbbeedabcedcadaaabbdaebbeadacabaaaa", "cebdeaaeabdeadeebedadebaeacdeea", "ceedeaeeaabaeaeaeadcdeacdedbdaddaaadcccdbbebcd", "ceeeebdcebbbdcdbbcadbebadcaeeaebdaaceacaeabdceaee","daaebabcbbcadeeebbcedaacbbd", "ecaabd" };
    int k = 5;
    alienDictionary(dictionary,k);
    return 0;
}
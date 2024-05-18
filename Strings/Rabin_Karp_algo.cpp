#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//String Matching algo in O(n+m). We use polynomial rolling hash function

vector<int> rabinKarp(string word, string pattern)
{
    const int p = 41;
    int n = pattern.size();
    int m = word.size();

    vector<long long> p_pow(max(n,m));
    p_pow[0] = 1;

    for (int i = 1; i < (int)p_pow.size(); i++)
    {
        p_pow[i] = (p_pow[i-1] * p) % MOD;
    }

    vector<long long> h(m + 1,0); //Hash Function

    for (int i = 0; i < m; i++) //Hash value of word
    {
        h[i+1] = (h[i] + (word[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    long long h_s = 0;
    for (int i = 0; i < n; i++) //Hash value of pattern
    {
        h_s = (h_s + (pattern[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    vector<int>occurrences;

    for (int i = 0; i + n - 1 < m; i++)
    {
        long long cur_h = (h[i + n] + MOD - h[i])%MOD;
        if (cur_h == (h_s * p_pow[i]) % MOD)
        {
            occurrences.push_back(i);
        }
    }
    return occurrences;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word,pattern;
    cin>>word;
    cin>>pattern;

    vector<int>indicesOfOccurrences = rabinKarp(word,pattern);

    cout<<indicesOfOccurrences.size()<<endl;

    return 0;
}
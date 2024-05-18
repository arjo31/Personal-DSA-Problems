#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//Naive O(nm) //This basically just counts the number of occurences of pattern in string
int countNumberOfOccurrences(string word, string pattern)
{
    int n = word.size();
    int m = pattern.size();
    int i = 0, count = 0;
    while (i < n)
    {
        if (word[i]==pattern[0])
        {
            int j = 0;
            int dummyi = i;
            while (j < m)
            {
                if (word[dummyi]==pattern[j])
                {
                    dummyi++;
                    j++;
                }
                else break;
                if (j==m) count++;
            }
        }
        i++;
    }
    return count;
}

//KMP (Knuth - Morris - Pratt) Algo is a string matching algo..Finds index of first occurence of pattern in a string O(n + m)
vector<int> prefixFunc(string s)
{
    int n = s.size();
    vector<int>pi(n,0);
    int i = 1, prevPI = 0;
    while (i < n)
    {
        if (s[i]==s[prevPI])
        {
            pi[i] = prevPI + 1;
            prevPI++;
            i++;
        }
        else if (prevPI==0)
        {
            pi[i] = 0;
            i++;
        }
        else
        {
            prevPI = pi[prevPI - 1];
        }
    }
    return pi;
}

int kmpAlgo(string word, string pattern)
{
    int n = word.size();
    int m = pattern.size();
    vector<int>res = prefixFunc(pattern);
    int pos = -1;
    int i = 0, j = 0, count = 0;
    while (i < n)
    {
        if (word[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j!=0)
            {
                j = res[j-1];
            }
            else
            {
                i++;
            }
        }
        if (j==m)
        {
            pos = i - m;
            break;
        }
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, pattern;
    cin>>s;
    cin>>pattern;
    cout<<kmpAlgo(s,pattern)<<endl;

    return 0;
}
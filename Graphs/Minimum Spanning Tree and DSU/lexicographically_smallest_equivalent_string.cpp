/*You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

1. Reflexivity: 'a' == 'a'.
2. Symmetry: 'a' == 'b' implies 'b' == 'a'.
3. Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.

For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.*/

#include <bits/stdc++.h>
using namespace std;

// DFS
char DFS(unordered_map<char, vector<char>> &adj, char curr, vector<int> &visited)
{
    visited[curr - 'a'] = 1;

    char minChar = curr;

    for (char &v : adj[curr])
    {

        if (visited[v - 'a'] == 0)
            minChar = min(minChar, DFS(adj, v, visited));
    }

    return minChar;
}

string smallestEquivalentString(string s1, string s2, string baseStr)
{
    int n = s1.length();
    unordered_map<char, vector<char>> adj;

    for (int i = 0; i < n; i++)
    {
        char u = s1[i];
        char v = s2[i];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m = baseStr.length();
    string result;

    for (int i = 0; i < m; i++)
    {
        char ch = baseStr[i];

        vector<int> visited(26, 0);

        result.push_back(DFS(adj, ch, visited));
    }

    return result;
}

// DSU
class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int ultimateParent(int node)
    {
        if (parent[node] == node)
            return parent[node];
        return parent[node] = ultimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        u = ultimateParent(u);
        v = ultimateParent(v);
        if (u > v)
            parent[u] = v;
        else
            parent[v] = u;
    }
};

string smallestEquivalentString(string s1, string s2, string baseStr)
{
    if (s1.size() != s2.size())
        return "";
    int n = s1.size();
    DisjointSet ds(25);
    for (int i = 0; i < n; i++)
    {
        char c1 = s1[i];
        char c2 = s2[i];
        if (c1 > c2)
            swap(c1, c2);
        if (ds.ultimateParent(c1 - 'a') != ds.ultimateParent(c2 - 'a'))
            ds.unionBySize(c1 - 'a', c2 - 'a');
    }
    string ans = "";
    for (char c : baseStr)
    {
        ans += (ds.ultimateParent(c - 'a') + 'a');
    }
    return ans;
}
/*You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.*/

#include <bits/stdc++.h>
using namespace std;

// Shows Memory Limit Exceeded
int longestPath(vector<int> &parent, string s)
{
    int n = parent.size();
    vector<int> adj[n];
    for (int i = 1; i < n; i++)
    {
        adj[parent[i]].push_back(i);
        adj[i].push_back(parent[i]);
    }
    int ans = 1;
    dfs(0, -1, adj, ans, s);
    return ans;
}

int dfs(int node, int parent, vector<int> adj[], int &ans, string s)
{
    int maxHeight = 0;
    char currChar = s[node];
    int currAnswer = 1;
    for (int child : adj[node])
    {
        char childChar = s[child];
        if (parent == child)
            continue;
        int childAnswer = dfs(child, node, adj, ans, s);
        if (currChar != childChar)
        {
            maxHeight = max(maxHeight, childAnswer);
            currAnswer = currAnswer + childAnswer;
        }
    }
    ans = max(ans, currAnswer);
    return 1 + maxHeight;
}

// Better option
int longestPath(vector<int> &parent, string s)
{
    int n = parent.size();
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        adj[parent[i]].push_back(i);
        adj[i].push_back(parent[i]);
    }
    int ans = 1;
    dfs(0, -1, adj, ans, s);
    return ans;
}

int dfs(int node, int parent, vector<vector<int>> &adj, int &ans, string s)
{
    int firstLongestChild = 0;
    int secondLongestChild = 0;
    char currChar = s[node];
    for (int child : adj[node])
    {
        if (child == parent)
            continue;
        char childChar = s[child];
        int childAnswer = dfs(child, node, adj, ans, s);
        if (childChar == currChar)
            continue;
        if (childAnswer > secondLongestChild)
            secondLongestChild = childAnswer;
        if (firstLongestChild < secondLongestChild)
            swap(firstLongestChild, secondLongestChild);
    }
    int temp = max(firstLongestChild, secondLongestChild) + 1;
    int currAns = max(temp, firstLongestChild + secondLongestChild + 1);
    ans = max(ans, currAns);
    return temp;
}
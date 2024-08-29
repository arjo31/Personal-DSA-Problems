/*You are given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. The root of the tree is the node 0, and each node of the tree has a label which is a lower-case character given in the string labels (i.e. The node with the number i has the label labels[i]).

The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.

Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.*/

#include <bits/stdc++.h>
using namespace std;

// Approach-1 (DFS - adding counts from children at every node)
vector<int> DFS(unordered_map<int, vector<int>> &adj, int u, int parent, vector<int> &result, string &labels)
{
    vector<int> myCount(26, 0);
    char myLabel = labels[u];

    myCount[myLabel - 'a'] = 1;

    for (int &v : adj[u])
    {
        if (v == parent)
            continue;

        vector<int> childCount(26, 0);
        childCount = DFS(adj, v, u, result, labels);

        for (int i = 0; i < 26; i++)
            myCount[i] += childCount[i];
    }
    result[u] = myCount[myLabel - 'a'];
    return myCount;
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    unordered_map<int, vector<int>> adj;

    for (auto &vec : edges)
    {
        int u = vec[0];
        int v = vec[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result(n, 0);

    DFS(adj, 0, -1, result, labels);

    return result;
}

// Approach-2 (DFS - No need to add count at everynode)
vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    unordered_map<int, vector<int>> adj;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> results(n, 0);
    vector<int> count(26, 0);
    dfs(adj, 0, -1, results, count, labels);
    return results;
}

void dfs(unordered_map<int, vector<int>> &adj, int node, int parent, vector<int> &results, vector<int> &count, string labels)
{
    char myLabel = labels[node];
    int countBeforeVisitingCurrChildren = count[myLabel - 'a'];
    count[myLabel - 'a'] += 1;

    for (int child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(adj, child, node, results, count, labels);
    }
    int countAfterVisitingCurrChildren = count[myLabel - 'a'];
    results[node] = countAfterVisitingCurrChildren - countBeforeVisitingCurrChildren;
}
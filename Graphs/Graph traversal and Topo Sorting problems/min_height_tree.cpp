/*A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1)
        return {0};

    vector<int> adj[n + 1];
    vector<int> degrees(n + 1, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        degrees[u]++;
        degrees[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (degrees[i] == 1)
            q.push(i);
    }
    int remNodes = n;
    while (remNodes > 2)
    {
        int size = q.size();
        remNodes = remNodes - size;
        for (int i = 0; i < size; i++)
        {
            int leaf = q.front();
            q.pop();
            for (int neighbour : adj[leaf])
            {
                degrees[neighbour]--;
                if (degrees[neighbour] == 1)
                    q.push(neighbour);
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}
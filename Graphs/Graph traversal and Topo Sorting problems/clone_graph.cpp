/*Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{
    unordered_map<Node *, Node *> mpp;
    if (node == nullptr)
        return node;
    if (node->neighbors.size() == 0)
    {
        Node *clone = new Node(node->val);
        return clone;
    }
    return dfs(node, mpp);
}

Node *dfs(Node *node, unordered_map<Node *, Node *> &mpp)
{
    vector<Node *> neighbor;
    Node *clone = new Node(node->val);
    mpp[node] = clone;
    for (auto it : node->neighbors)
    {
        if (mpp.find(it) != mpp.end())
            neighbor.push_back(mpp[it]);
        else
            neighbor.push_back(dfs(it, mpp));
    }
    clone->neighbors = neighbor;
    return clone;
}
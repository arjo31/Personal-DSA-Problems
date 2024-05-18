/*Eulerian Cycle: An undirected graph has Eulerian cycle if following two conditions are true.

1. All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
2. All vertices have even degree.

Eulerian Path: An undirected graph has Eulerian Path if following two conditions are true.

1. Same as condition (a) for Eulerian Cycle.
2. If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)


*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[];

void dfs(int node, vector<bool> &vis)
{
    vis[node] = 1;

    for (int v : adj[node])
    {
        if (!vis[node])
        {
            dfs(v, vis);
        }
    }
}

bool isConnected()
{
    vector<bool> vis(n, false);
    int i;

    int connectedComponents = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (connectedComponents == 1)
                return false;
            dfs(i, vis);
            connectedComponents++;
        }
    }

    return true;
}

int isEulerian()
{
    if (!isConnected())
        return 0;
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() & 1)
            odd++;
    }

    if (odd > 2)
        return 0;
    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd) ? 1 : 2;
}

void test()
{
    int result = isEulerian();
    if (result == 0)
        cout << "Not Eulerian" << endl;
    else if (result == 1)
        cout << "Eulerian path exists" << endl;
    else
        cout << "Eulerian cycle exists" << endl;
}
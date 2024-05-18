/*In a region consisting of N towns, there are M bidirectional roads connecting these towns. Each road is of equal length. In this region, there are two types of armies stationed: the Red Army and the Blue Army. The Red Army is stationed in R distinct towns, and the Blue Army is stationed in B distinct towns, with no town hosting both a Red and a Blue army unit simultaneously.

Find the minimum amount of time required for any two armies of different colors to clash. It is known that an army can travel from one town to another across any road in exactly one day. Consider all possible paths and scenarios in which the two armies might travel and clash. Armies can move independently and simultaneously.

If two armies can never clash, then print "-1".*/

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> &dist, queue<pair<int, int>> &q, vector<int> adj[])
{
    while (!q.empty())
    {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        for (int v : adj[node])
        {
            if (d + 1 < dist[v])
            {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> army(n);
    for (int i = 0; i < n; i++)
        cin >> army[i];
    vector<int> dist1(n + 1, 1e9);
    vector<int> dist2(n + 1, 1e9);
    queue<pair<int, int>> q;
    vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (army[i] == 1)
        {
            q.push({i + 1, 0});
            dist1[i + 1] = 0;
        }
    }

    bfs(dist1, q, adj);

    for (int i = 0; i < n; i++)
    {
        if (army[i] == 2)
        {
            q.push({i + 1, 0});
            dist2[i + 1] = 0;
        }
    }

    bfs(dist2, q, adj);

    double minDist = 1e9;
    for (int i = 1; i <= n; i++)
    {
        if (dist1[i] != 1e9 && dist2[i] != 1e9)
        {
            minDist = min(minDist, (dist1[i] + dist2[i]) / (2.0));
        }
    }
    if (minDist == 1e9)
    {
        cout << -1 << endl;
    }
    else
        cout << minDist << endl;
    return 0;
}

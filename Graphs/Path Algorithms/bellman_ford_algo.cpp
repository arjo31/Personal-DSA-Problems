//Shortest path algo which works for negative edges as well as well as negative cycle
//Applicable only in directed graph

//If given undirected graph, change it to directed graph

// n - 1 iterations

//Time Complexity O(V^2)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Edge
{
	int a,b,cost;
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m;
	cin>>n>>m;
	vector<Edge>edges(m);
	for (int i = 0; i < m; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edges[i].a = u;
		edges[i].b = v;
		edges[i].cost = w;
	}

	vector<int>dist(n+1,1e9);
	dist[1] = 0;
    vector<int>path(n+1,-1);
	// for (int i = 0; i < n-1; i++)
	// {
	// 	for (Edge e : edges)
	// 	{
	// 		if (dist[e.a] < 1e9)
	// 		{
	// 			dist[e.b] = min(dist[e.b], dist[e.a] + e.cost);
    //             path[e.b] = e.a;
	// 		}
	// 	}
	// }
    //Detect Negative Cycle
    //after (n-1)th  phase, if we run algorithm for one more phase, and it performs at least one more relaxation, then the graph contains a negative weight cycle that is reachable from v; otherwise, such a cycle does not exist.
    
    // For this, it is sufficient to remember the last vertex x for which there was a relaxation in nth phase. This vertex will either lie in a negative weight cycle, or is reachable from it. To get the vertices that are guaranteed to lie in a negative cycle, starting from the vertex x, pass through to the predecessors n times. Hence we will get the vertex y, namely the vertex in the cycle earliest reachable from source. We have to go from this vertex, through the predecessors, until we get back to the same vertex y (and it will happen, because relaxation in a negative weight cycle occur in a circular manner).
    int x;
    for (int i = 1; i <= n; ++i)
    {
        x = -1;
        for (Edge e : edges)
            if (dist[e.a] < 1e9)
                if (dist[e.b] > dist[e.a] + e.cost){
                    dist[e.b] = fmax(-1e9, min(dist[e.b],dist[e.a] + e.cost));
                    path[e.b] = e.a;
                    x = e.b;
                }
        cout<<i<<"th iteration : ";
        for (auto it : dist) cout<<it<<" ";
        cout<<endl;
    }
    if (x == -1)
        cout << "No negative cycle found ";
    else {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = path[y];
        vector<int> cycle;
        int cur = y;
        cycle.push_back(cur);
        cur = path[cur];
        while(cur!=y)
        {
            cycle.push_back(cur);
            cur = path[cur];
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int u : cycle)
            cout << u << ' ';
    }
    // if (dist[n] == 1e9)
    //     cout << "No path from " << 1 << " to " << n << ".";
    // else {
    //     vector<int> p;
    //     int cur = n;
    //     while (cur!=-1)
    //     {
    //         p.push_back(cur);
    //         cur = path[cur];
    //     }
    //     reverse(p.begin(), p.end());

    //     cout << "Path from " << 1 << " to " << n << ": ";
    //     for (int u : p)
    //         cout << u << ' ';
    // }
    return 0;
}
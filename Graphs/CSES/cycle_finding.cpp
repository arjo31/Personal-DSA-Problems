//Atcoder DP Educational
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

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
	vector<int>dist(n+1,INF);
	vector<int>path(n+1,-1);
	dist[1] = 0;
	int x;
	for (int i = 1; i<=n; i++)
	{
		x = -1;
		for (Edge e : edges)
		{
			if (dist[e.b] > dist[e.a] + e.cost)
			{
				dist[e.b] = max(-INF, min(dist[e.b], dist[e.a] + e.cost));
				path[e.b] = e.a;
				x = e.b;
			}
		}
		// cout<<i<<"th iteration : ";
		// for (auto it : dist) cout<<it<<" ";
		// cout<<endl;
	}

	if (x==-1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		cout<<"YES"<<endl;
		int y = x;
		for (int i = 1; i <= n; i++)
		{
			y = path[y];
		}
		vector<int>cycle;
		int curr = y;
		cycle.push_back(curr);
		curr = path[curr];
		while (curr!=y)
		{
			cycle.push_back(curr);
			curr = path[curr];
		}
		cycle.push_back(y);
		reverse(cycle.begin(), cycle.end());
		for (auto it : cycle) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
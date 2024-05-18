//Used for maximum flow problems. TE : O(V*E^2)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

typedef long long int ll;

bool bfs(int src, int target,vector<int>&parent, vector<int>&pathFlow, vector<int>adj[], vector<vector<int>>&capacity, vector<vector<int>>&flowPassed)
{
    fill(parent.begin(), parent.end(), -1);
    fill(pathFlow.begin(), pathFlow.end(), 0);
	queue<int>q;
	q.push(src);
	pathFlow[src] = INF;
	parent[src] = -2;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (auto v : adj[u])
		{
			if (parent[v]==-1)
			{
				if (capacity[u][v] - flowPassed[u][v] > 0)
				{
					parent[v] = u;
					pathFlow[v] = min(pathFlow[u], capacity[u][v] - flowPassed[u][v]);
					if (v==target) return true;
					q.push(v);
				}
			}
		}
	}
	return false;
}


void printArray(vector<int>arr)
{
	for (auto it : arr) cout<<it<<" ";
	cout<<endl;
}

int edmondKarp(int src, int target, vector<int>&parent, vector<int>&pathFlow, vector<int>adj[], vector<vector<int>>&capacity, vector<vector<int>>&flowPassed)
{
	int maxFlow = 0;
	while (1)
	{
		int flow = bfs(src,target,parent,pathFlow,adj,capacity,flowPassed);
		if (flow==0)
		{
			break;
		}
		int u = target;
		maxFlow+=flow;
		while (u!=src)
		{
			int v = parent[u];
			flowPassed[v][u]+=flow;
			flowPassed[u][v]-=flow;
			u = v;
		}
	}
	return maxFlow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<vector<int>>capacity(n+1, vector<int>(n+1,0));
    vector<vector<int>>flowPassed(n+1, vector<int>(n+1,0));
    for (int i = 0; i < m; i++)
    {
    	int from,to,cap;
    	cin>>from>>to>>cap;
    	capacity[from][to] = cap;
    	adj[from].push_back(to);
    	adj[to].push_back(from);
    }
    vector<int>parent(n+1,-1);
    vector<int>pathFlow(n+1,0);
    cout<<edmondKarp(1,n,parent,pathFlow,adj,capacity,flowPassed)<<endl;
    return 0;
}
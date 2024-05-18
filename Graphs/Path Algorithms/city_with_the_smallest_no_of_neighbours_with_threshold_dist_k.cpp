#include <bits/stdc++.h>
using namespace std;

void floydWarshall(int n,vector<vector<int>>&edges,vector<vector<int>>&cost)
{
	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		cost[u][v] = w;
		cost[v][u] = w;
	}
	for (int i = 0; i < n; i++)
	{
		cost[i][i] = 0;
	}
	for (int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (cost[i][k]!=1e9 && cost[k][j]!=1e9)
				{
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}
	}
}
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) 
{
	vector<vector<int>>cost(n,vector<int>(n,1e9));
    floydWarshall(n,edges,cost);
	vector<int> adj[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cost[i][j]<=distanceThreshold && i!=j)
			{
				adj[i].push_back(j);
			}
		}
	}
	int len;
	int ans = INT_MAX;
	int city = 0;
	for (int i = 0; i < n; i++)
	{
		len = adj[i].size();
		if (len<=ans)
		{
			ans = len;
			city = i;
		}
	}
	return city;
}
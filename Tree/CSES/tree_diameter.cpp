#include <bits/stdc++.h>
using namespace std;

int height[200001];

vector<int>adj[200001];

void dfs(int node, int parent)
{
	if (parent==-1)
	{
		height[node] = 0;
	}
	else
	{
		height[node] = height[parent] + 1;
	}
	for (auto child : adj[node])
	{
		if (child==parent) continue;
		dfs(child,node);
	}
}

int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n-1; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	int maxHeight = 0;
	int node = -1;
	//Basically Diameter of a tree is found by first finding the node farthest away from the root node 1. After finding that node, we are going to find the maximum height of the tree from that node. That will give us the diameter.
	for (int i = 1; i <= n; i++)
	{
		if (height[i]>=maxHeight)
		{
			maxHeight = height[i];
			node = i;
		}
		height[i] = 0;
	}
	dfs(node,-1);
	cout<<*max_element(height, height+n)<<endl;
	return 0;
}
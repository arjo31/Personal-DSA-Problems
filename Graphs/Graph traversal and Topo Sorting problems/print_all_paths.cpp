#include <bits/stdc++.h>
using namespace std;

void findAllPaths(vector<int>adj[], int currNode, vector<int>&vis, int n, vector<int>&currPath, vector<vector<int>>&res)
{
    if (currNode==n-1)
    {
        res.push_back(currPath);
        return ;
    }

    if (vis[currNode]) return;
    vis[currNode] = 1;

    for (auto neighbour : adj[currNode])
    {
        currPath.push_back(neighbour);
        findAllPaths(adj,neighbour,vis,n,currPath,res);
        currPath.pop_back();
    }
    vis[currNode] = 0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<vector<int>> res;
    vector<int> currPath;
    vector<int>vis(n,0);

    currPath.push_back(0);

    findAllPaths(adj,0,vis,n,currPath,res);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
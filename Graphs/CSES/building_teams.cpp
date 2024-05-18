#include<bits/stdc++.h>
using namespace std;

bool isPossible(int node,vector<int>adj[], vector<int>&vis,vector<int>&group,queue<pair<int,int>>&q)
{
    vis[node] = 1;
    q.push({1,node});
    while (!q.empty())
    {
        int parent = q.front().first;
        int current = q.front().second;
        q.pop();

        for (auto adjNode : adj[current])
        {
            if(vis[adjNode]==0)
            {
                if (group[current]==1)
                {
                    group[adjNode] = 2;
                }
                else if (group[current]==2)
                {
                    group[adjNode] = 1;
                }
                vis[adjNode] = 1;
                q.push({current,adjNode});
            }
            else if (parent!=adjNode)
            {
                if (group[adjNode]==group[current])
                {
                    return false;
                }
            }
        }
    }
    return true;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u,v; 
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    vector<int>vis(n+1,0);
    vector<int>group(n+1,1);
    queue<pair<int,int>>q;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (!isPossible(i,adj,vis,group,q))
            {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<group[i]<<" ";
    }
    return 0;
}
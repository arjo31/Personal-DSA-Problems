#include <bits/stdc++.h>
using namespace std;

vector<int>path;

void dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    path.push_back(node);
    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            dfs(adjNode,node,adj,vis);
        }
        else if (parent==adjNode) continue;
        else if (parent!=adjNode)
        {
            if (path.size()>=2)
            {
                vector<int>ans;
                path.push_back(adjNode);
                ans.push_back(adjNode);
                for (int i = path.size()-2;i>=0;i--)
                {
                    if (path[i]!=adjNode)
                    {
                        ans.push_back(path[i]);
                    }
                    else
                    {
                        ans.push_back(path[i]);
                        break;
                    }
                }
                cout<<ans.size()<<endl;
                for (auto it : ans)
                {
                    cout<<it<<" ";
                }
                cout<<endl;
                exit(0);
            }
        }
    }
    path.pop_back();
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n+1,0);
    for (int i = 1; i<=n; i++)
    {
        if (!vis[i])
        {
            dfs(i,-1,adj,vis);
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void printCycle(int node,int parent, vector<int>adj[], vector<int>&vis,vector<int>&bigvis,vector<int>&path)
{
    bigvis[node] = 1;
    vis[node] = 1;
    path.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {   
            if (bigvis[it]) continue;
            printCycle(it,node,adj,vis,bigvis,path);
        }
        else
        {
            if (path.size()>=2)
            {
                vector<int>ans;
                path.push_back(it);
                ans.push_back(it);
                path.pop_back();
                while (path.back()!=it)
                {
                    ans.push_back(path.back());
                    path.pop_back();
                }
                ans.push_back(it);
                reverse(ans.begin(), ans.end());
                cout<<ans.size()<<endl;
                for (auto it : ans) cout<<it<<" ";
                cout<<endl;
                exit(0);
            }
        }
    }
    vis[node] = 0;
    path.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>path;
    vector<int>vis(n+1,0);
    vector<int>bigvis(n+1,0);
    for (int i = 1; i<=n; i++)
    {
        if (!bigvis[i]) printCycle(i,-1,adj,vis,bigvis,path);
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
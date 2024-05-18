#include <bits/stdc++.h>
using namespace std;

int timer = 0;

//Articulation points are those nodes on whose removal, the graph breaks down into multiple components

void dfs(int node, int parent,vector<int>&vis,vector<int>&timeIn,vector<int>&lowTime,vector<int>&mark,vector<int>adj[])
{
    vis[node] = 1;
    timeIn[node] = lowTime[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it,node,vis,timeIn,lowTime,mark,adj);
            lowTime[node] = min(lowTime[node],lowTime[it]);
            if(lowTime[node] >= timeIn[node] && parent!=-1)
            {
                mark[node] = 1;
            }
            child++;
        }
        else
        {
            lowTime[node] = min(lowTime[node],timeIn[it]);
        }
    }
    if(child>1&&parent==-1)
    {
        mark[node] = 1;
    }
}

vector<int> articulationPoints(int n, vector<int>adj[])
{
    vector<int> vis(n,0);
    vector<int> timeIn(n);
    vector<int> lowTime(n);
    vector<int>mark(n,0);
    for(int i = 0; i < n ; i++)
    {
        if (!vis[i])
        {
            dfs(i,-1,vis,timeIn,lowTime,mark,adj);
        }
    }
    vector<int>ans;
    for(int i = 0 ;i < n ; i++)
    {
        if (mark[i]==1)
        {
            ans.push_back(i);
        }
    }
    if (ans.size()==0) return {-1};
    return ans;
}

/*#include<bits/stdc++.h>
using namespace std;
int timer=0;
void dfs(int node,int par,int tin[],int low[],vector<int>adj[],vector<int>&mark,vector<int>&vis)
{
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    int child=0;
    for(auto i:adj[node])
    {
        if(i==par)continue;
        if(!vis[i])
        {
          dfs(i,node,tin,low,adj,mark,vis);
          low[node]=min(low[node],low[i]);
          if(low[i]>=tin[node]&& par!=-1)
                 mark[node]=1;
          child++;
        }
        else
        {
          low[node]=min(low[node],tin[i]);
        }
    }
    if(child>1 && par==-1)mark[node]=1;
}
void Articulation(vector<int>adj[],int v,vector<int>&ans)
{
   int tin[v];
   int low[v];
   vector<int>vis(v,0);
   for(int i=1;i<v;i++)
   {
   if(!vis[i])dfs(i,-1,tin,low,adj,ans,vis);
   }
}
int main(){
    int tcase;
    cin>>tcase;
    while(tcase--)
    {
        int v,e;
        cin>>v>>e;
        vector<int>adj[v+1];
        while(e--)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans(v+1,0);
        Articulation(adj,v+1,ans);
        for(int i=1;i<=v;i++)
        {
            if(ans[i])cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/
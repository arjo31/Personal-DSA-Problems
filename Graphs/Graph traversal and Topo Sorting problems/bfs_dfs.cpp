#include <bits/stdc++.h>
using namespace std;

class GraphTraversals
{
    private:
        void dfs(int node, vector<int>adj[], int vis[], vector<int> &dfs_list)
        {
            vis[node] = 1;
            dfs_list.push_back(node);
            //Traverse all its neighbours
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    dfs(it,adj,vis,dfs_list);
                }
            }
        }

    public:
        vector<int> bfsOfGraph(int V, vector<int>adj[])
        {
            int vis[V] = {0};
            vis[0] = 1;

            queue<int>q;
            q.push(0);
            vector<int> bfs;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            return bfs;
        }

        vector<int> dfsOfGraph(int V, vector<int>adj[])
        {
            int vis[V] = {0};
            int start = 0;
            vector<int> dfs_list;
            dfs(start,adj,vis,dfs_list);
            return dfs_list;
        }
};
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    public:
        vector<int> parent,size,rank;
        DisjointSet(int V)
        {
            parent.resize(V+1);
            rank.resize(V+1,0);
            size.resize(V+1,1);
            for (int i = 0; i<=V; i++)
            {
                parent[i] = i;
            }
        }

        int findUParent(int node)
        {
            if (node==parent[node])
            {
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v)
        {
            u = findUParent(u);
            v = findUParent(v);
            if (u==v) return ;
            if (rank[u] < rank[v])
            {
                parent[u] = v;
            }
            else if (rank[u] > rank[v])
            {
                parent[v] = u;
            }
            else
            {
                parent[v] = u;
                rank[u]++;
            }
        }

        void unionBySize(int u, int v)
        {
            u = findUParent(u);
            v = findUParent(v);
            if (u==v) return ;
            if (size[u] < size[v])
            {
                parent[u] = v;
                size[v]+=size[u];
            }
            else
            {
                parent[v] = u;
                size[u]+=size[v];
            }
        }
};

vector<vector<string>> mergeDetails(vector<vector<string>>&details)
{
    int V = details.size();
    unordered_map<string,int>mpp;
    DisjointSet ds(V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 1; j < details[i].size(); j++)
        {
            string mail = details[i][j];
            if (mpp.find(mail)==mpp.end()) //Mail not found
            {
                mpp[mail] = i;
            }
            else
            {
                ds.unionByRank(i,mpp[mail]);
            }
        }
    }
    vector<string> mergeMail[V];
    for(auto it : mpp)
    {   
        string mail = it.first;
        int node = ds.findUParent(it.second);
        mergeMail[node].push_back(mail);
    }
    vector<vector<string>>ans;
    for(int i = 0; i<V; i++)
    {
        if (mergeMail[i].size()==0) continue;
        sort(mergeMail[i].begin(), mergeMail[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for(auto it: mergeMail[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}
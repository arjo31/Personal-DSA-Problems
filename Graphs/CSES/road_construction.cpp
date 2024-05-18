#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    public:
        vector<int>parent,size;

        DisjointSet(int n)
        {
            parent.resize(n+1);
            size.resize(n+1);
            for (int i = 0; i<=n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUParent(int u)
        {
            if (parent[u]==u) return u;
            return parent[u] = findUParent(parent[u]);
        }

        void unionBySize(int u, int v)
        {
            int ult_u = findUParent(u);
            int ult_v = findUParent(v);
            if (ult_u==ult_v) return;
            else if (size[ult_u] < size[ult_v])
            {
                parent[ult_u] = ult_v;
                size[ult_v]+=size[ult_u];
            }
            else
            {
                parent[ult_v] = ult_u;
                size[ult_u]+=size[ult_v];
            }
        }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    DisjointSet ds(n+1);
    int count = 0;
    int maxSize = 0;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if (ds.findUParent(u)!=ds.findUParent(v))
        {
            count++;
            ds.unionBySize(u,v);
            maxSize = max({maxSize,ds.size[ds.findUParent(u)],ds.size[ds.findUParent(v)]});
        }
        cout<<(n-count)<<" "<<maxSize<<endl;

    }

    return 0;
}
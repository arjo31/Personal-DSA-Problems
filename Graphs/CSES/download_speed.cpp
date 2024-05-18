//Used for maximum flow problems. TE : O(E*Flow)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

typedef long long int ll;

ll capacity[510][510];
vector<vector<ll>>graph(510,vector<ll>(510,0));

ll bfs(ll src, ll target,ll V, vector<ll>&parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[src] = -2;
    queue<pair<ll,ll>>q;
    q.push({src,1e18});

    while (!q.empty())
    {
        ll u = q.front().first;
        ll cap = q.front().second;

        q.pop();

        for (ll v = 1; v<=V; v++)
        {
            if (parent[v]==-1 && capacity[u][v]!=0)
            {
                parent[v] = u;
                ll maxCap = capacity[u][v];
                ll minCap = min(cap, maxCap);
                if (v==target) return minCap;
                q.push({v,minCap});
            }
        }
    }
    return 0;
}

ll fordFulkerson(ll src, ll target, int V)
{
    vector<ll>parent(V+1,-1);

    ll maxFlow = 0;
    ll minCap = 0;

    while (minCap = bfs(src,target,V,parent))
    {
        maxFlow+=minCap;
        ll v = target;

        while (v!=src)
        {
            ll u = parent[v];
            capacity[u][v]-=minCap;
            capacity[v][u]+=minCap;
            v = u;
        }
    }
    return maxFlow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;
    for (ll i = 0; i < m; i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(v);
        capacity[u][v]+= w;
    }
    cout<<fordFulkerson(1,n,n);
    return 0;
}
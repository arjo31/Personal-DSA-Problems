#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1];
    for (ll i = 0; i < m; i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<ll>adjT[n+1];
    for (ll i = 1; i<=n; i++)
    {
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }
    vector<ll>dp(n+1,0);
    vector<ll>indegree(n+1,0);
    queue<ll> q;
    for (ll i = 1; i<=n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (ll i = 1; i<=n; i++)
    {
        if (indegree[i]==0) q.push(i);
    }

    vector<ll>list;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        list.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it]==0) q.push(it);
        }
    }

    reverse(list.begin(), list.end());
    
    ll finalIndex = 0;
    for (ll i = 0; i < (ll)list.size(); i++)
    {
        if (list[i]==n)
        {
            finalIndex = i;
            break;
        }
    }
    dp[n] = 1;
    vector<ll>prev_node(n+1,0);
    for (ll i = finalIndex ; i < (ll)list.size(); i++)
    {
        for (auto it : adjT[list[i]])
        {
            if (1 + dp[list[i]] > dp[it])
            {
                dp[it] = 1 + dp[list[i]];
                prev_node[it] = list[i];
            }
        }
    }
    vector<ll>path;
    ll ind = 1;
    path.push_back(1);
    while (ind!=n)
    {
        path.push_back(prev_node[ind]);
        ind = prev_node[ind];
        if (ind==0)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<dp[1]<<endl;
    for (ll i = 0; i < (ll)path.size(); i++) cout<<path[i]<<" ";
    cout<<endl;
    return 0;
}
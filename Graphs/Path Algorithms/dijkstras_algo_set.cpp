#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstrasAlgo(int V, vector<vector<int>>adj[], int source)
{
    set <pair<int,int>> st; //Stores in ascending order
    vector<int> dist(V,1e9);

    st.insert({0,source});
    dist[source] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int wt = it[1];

            if (dis + wt < dist[adjNode])
            {
                if (dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode] = wt + dis;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
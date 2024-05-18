#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<long long int>>&matrix)
{
    long long int n = matrix.size()-1;
    for(long long int k = 1; k <= n; k++)
    {
        for(long long int i = 1; i <= n; i++)
        {
            for (long long int j = 1; j <= n; j++)
            {
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
}

int main()
{
    long long int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long int>>matrix(n+1,vector<long long int>(n+1,1e17));
    for (long long int i = 1; i<=m; i++)
    {
        long long int u,v,w;
        cin>>u>>v>>w;
        matrix[u][v] = min(w,matrix[u][v]);
        matrix[v][u] = min(w,matrix[v][u]);
    }
    for (int i = 0; i <= n ;i++)
    {
        matrix[i][i] = 0;
    }
    floydWarshall(matrix);
    while (q--)
    {
        long long int a,b;
        cin>>a>>b;
        if (matrix[a][b]==1e17) cout<<-1<<endl;
        else cout<<matrix[a][b]<<endl;
    }
    return 0;
}
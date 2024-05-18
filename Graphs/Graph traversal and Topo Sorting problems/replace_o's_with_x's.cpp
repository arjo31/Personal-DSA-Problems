#include <bits/stdc++.h>
using namespace std;

//DFS algorithm is applied

void dfs(int r, int c, vector<vector<int>>&vis,vector<vector<char>>&mat)
{
    vis[r][c] = 1;

    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = r + drow[i];
        int ncol = c + dcol[i];
        if ((nrow>=0 && nrow < mat.size()) && (ncol>=0 && ncol < mat[0].size()) && !vis[nrow][ncol] && mat[nrow][ncol]=='o')
        {
            dfs(nrow,ncol,vis,mat);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>>mat)
{
    vector<vector<int>> vis(n,vector<int>(m,0));
    //Traverse first row and last row
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && mat[0][j]=='o')
        {
            dfs(0,j,vis,mat);
        }

        if (!vis[n-1][j] && mat[n-1][j]=='o')
        {
            dfs(n-1,j,vis,mat);
        }
    }

    //Traverse first column and last column
    //Traverse first row and last row
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && mat[i][0]=='o')
        {
            dfs(i,0,vis,mat);
        }

        if (!vis[i][m-1] && mat[i][m-1]=='o')
        {
            dfs(i,m-1,vis,mat);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j]=='o')
            {
                mat[i][j] = 'x';
            }
        }
    }
    return mat;   
}
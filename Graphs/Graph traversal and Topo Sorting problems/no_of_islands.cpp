#include <bits/stdc++.h>
using namespace std;

//Number of connected components in 2D matrix

void bfs(vector<vector<int>>&islands, vector<vector<int>>&vis, int row, int column)
{
    int n = islands.size();
    int m = islands[0].size();
    vis[row][column] = 1;
    queue<pair<int,int>> q;
    q.push({row,column});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        vector<int> drow = {-1,-1,0,1,1,1,0,-1};
        vector<int> dcol = {0,1,1,1,0,-1,-1,-1};
        for (int i = 0; i<8; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if ((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol <m) && !vis[nrow][ncol] && islands[nrow][ncol])
            {
                q.push({nrow,ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
}

int noOfIslands(vector<vector<int>>&islands)
{
    int n = islands.size();
    int m = islands[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && islands[i][j]==1)
            {
                count++;
                bfs(islands,vis,i,j);
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> islands = {
        {0,0,1,1,0},
        {1,0,1,1,0},
        {0,1,0,0,0},
        {0,0,0,0,1},
    };
    cout<<noOfIslands(islands)<<endl;
}
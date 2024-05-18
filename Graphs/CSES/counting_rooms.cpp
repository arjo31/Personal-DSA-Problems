#include <bits/stdc++.h>
using namespace std;

vector<int>drow = {-1,0,1,0};
vector<int>dcol = {0,1,0,-1};

bool isValid(int n, int m, int row, int col)
{
    return ((row>=0 && row<n) && (col>=0 && col<m));
}

void bfs(int r, int c, vector<vector<char>>&grid, vector<vector<int>>&vis,queue<pair<int,int>>&q,int n, int m)
{
    vis[r][c] = 1;
    q.push({r,c});
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (isValid(n,m,nrow,ncol) && vis[nrow][ncol]==0 && grid[nrow][ncol]=='.')
            {
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }
}

int noOfRooms(int n, int m, vector<vector<char>>grid)
{
    queue<pair<int,int>>q;
    vector<vector<int>>vis(n,vector<int>(m,0));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j]==0 && grid[i][j]=='.')
            {
                count++;
                bfs(i,j,grid,vis,q,n,m);
            }
        }
    }
    return count;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<noOfRooms(n,m,grid)<<endl;
}
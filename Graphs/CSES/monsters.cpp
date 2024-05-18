#include <bits/stdc++.h>
using namespace std;
 
vector<int> drow = {-1,0,1,0};
vector<int> dcol = {0,1,0,-1};
vector<char> dir = {'U', 'R', 'D', 'L'};
 
bool isValid(int row, int col, int n, int m)
{
    return ((row>=0 && row<n) && (col>=0 && col<m));
}
 
bool isBoundary(int row, int col, int n, int m)
{
    return ((row==0 || row==n-1) || (col==0 || col==m-1));
}
 
void bfs(int row, int col,vector<vector<int>>&vis,vector<vector<int>>&dist1, vector<vector<char>>&matrix,queue<pair<int,pair<int,int>>>&q,vector<vector<char>>&directions, int n, int m)
{
    vis[row][col] = 1;
    q.push({0,{row,col}});
    while(!q.empty())
    {
        int steps = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
 
        if (isBoundary(r,c,n,m))
        {
            cout<<"YES"<<endl;
            cout<<steps<<endl;
            vector<char>path;
            while(r!=row || c!=col)
            {
                path.push_back(directions[r][c]);
                char d = directions[r][c];
                if (d=='U') r++;
                else if (d=='D') r--;
                else if (d=='L') c++;
                else if (d=='R') c--;
            }
            reverse(path.begin(),path.end());
            for (char p : path)
            {
                cout<<p;
            }
            cout<<endl;
            exit(0);
        }
 
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (isValid(nrow,ncol,n,m) && !vis[nrow][ncol] && ((steps+1)<dist1[nrow][ncol]) && matrix[nrow][ncol]=='.')
            {
                q.push({steps+1,{nrow,ncol}});
                dist1[row][col] = steps+1;
                vis[nrow][ncol] = 1;
                directions[nrow][ncol] = dir[i];
            }
        }
    }
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>matrix(n,vector<char>(m));
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j ++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>dist1(1001,vector<int>(1001,1e9));
    queue<pair<int,pair<int,int>>>q;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m ; j ++)
        {
            if (!vis[i][j] && matrix[i][j]=='M')
            {
                q.push({0,{i,j}});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        int steps = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
 
        for (int i = 0; i < 4 ; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
 
            if (isValid(nrow,ncol,n,m) && !vis[nrow][ncol] && (matrix[nrow][ncol]=='.'||matrix[nrow][ncol]=='A'))
            {
                if (steps+1 < dist1[nrow][ncol])
                {
                    q.push({steps+1,{nrow,ncol}});
                    dist1[nrow][ncol] = steps+1;
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m ; j++)
        {
            vis[i][j] = 0;
        }
    }
    vector<vector<char>> directions(n, vector<char>(m,' '));
    for (int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m ;j++)
        {
            if (matrix[i][j]=='A')
            {
                bfs(i,j,vis,dist1,matrix,q,directions,n,m);
                break;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1,0,1,0};
vector<int> dcol = {0,1,0,-1};
vector<char> dir = {'U', 'R', 'D', 'L'};

bool isValid(int row, int col, int n, int m)
{
    return ((row>=0 && row<n)&&(col>=0 && col<m));
}

void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid, priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>&q,vector<vector<char>>&directions, int n, int m)
{
    vis[row][col] = 1;
    while (!q.empty())
    {
        int steps = q.top().first;
        int r = q.top().second.first;
        int c = q.top().second.second;
        q.pop();

        if (grid[r][c]=='B')
        {
            cout<<"YES"<<endl;
            cout<<steps<<endl;
            vector<char>path;
            while (r!=row || c!=col)
            {
                path.push_back(directions[r][c]);
                char d = directions[r][c];
                if (d=='U')
                {
                    r++;
                }
                else if (d=='D')
                {
                    r--;
                }
                else if (d=='L')
                {
                    c++;
                }
                else if (d=='R')
                {
                    c--;
                }
            }
            reverse(path.begin(),path.end());
            for (char p : path)
            {
                cout<<p;
            }
            cout<<endl;
            return;
        }

        for (int i = 0 ; i < 4 ; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (isValid(nrow,ncol,n,m) && !vis[nrow][ncol] && (grid[nrow][ncol]=='.' || grid[nrow][ncol]=='B'))
            {
                vis[nrow][ncol] = 1;
                q.push({steps+1,{nrow,ncol}});
                directions[nrow][ncol] = dir[i];
            }
        }
    }
    cout<<"NO"<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<char>> directions(n, vector<char>(m,' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j]=='A')
            {
                q.push({0,{i,j}});
                bfs(i,j,vis,grid,q,directions,n,m);
            }
        }
    }
    return 0;
}
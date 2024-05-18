#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1,0,1,0};
vector<int> dcol = {0,1,0,-1};
vector<int> dir = {'U','R','D','L'};

bool isValid(int row, int col, int n)
{
    return ((row>=0 && row < n) && (col>=0 && col < n));
}

void dfs(int row, int col, vector<vector<int>>&matrix, vector<vector<int>>&vis, vector<vector<char>>&directions, int n,vector<string>&ans)
{
    vis[row][col] = 1;
    if (row==n-1 && col==n-1)
    {
        vector<char>path;
        while (row!=0 || col!=0)
        {
            char c = directions[row][col];
            path.push_back(c);
            if (c=='R')col--;
            else if (c=='D')row--;
            else if (c=='L') col++;
            else row++;
        }
        reverse(path.begin(), path.end());
        string a ="";
        for (char c : path)
        {
            a+=c;
        }
        ans.push_back(a);
    }
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (isValid(nrow,ncol,n) && matrix[nrow][ncol]==1 && !vis[nrow][ncol])
        {
            directions[nrow][ncol] = dir[i];
            dfs(nrow,ncol,matrix,vis,directions,n,ans);
            vis[nrow][ncol] = 0;
            directions[nrow][ncol] = '.';
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>vis(n,vector<int>(n,0));
    vector<vector<char>>directions(n,vector<char>(n,'.'));
    vector<string>ans;
    dfs(0,0,matrix,vis,directions,n,ans);
    for (auto str:ans)
    {
        cout<<str<<" ";
    }
    return 0;
};

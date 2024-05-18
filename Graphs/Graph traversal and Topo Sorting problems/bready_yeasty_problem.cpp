/*Imagine a slice of bread, represented as a two-dimensional grid with N rows and M columns. Each cell within this grid can be in one of three states:

Occupied by blue yeast (1).
Occupied by red yeast (2).
Unoccupied by any yeast (3).

Your need to simulate the multiplication process of both types of yeast over time, under the following conditions:

At each second, both blue and red yeasts spread to adjacent unoccupied cells (up, down, left, right).
If an unoccupied cell is simultaneously approached by both blue and red yeasts, it houses both yeasts and looks visibly green!
Print final state of the bread slice after the multiplication process has stabilized and no further changes occur.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

bool isPossible(int row, int n, int col, int m)
{
    return (row >= 0 && row < n) && (col >= 0 && col < m);
}

void bfs(vector<vector<int>> &mat, vector<vector<int>> &vis, queue<pair<int, pair<int, int>>> &q, int yeastColor)
{
    int n = mat.size();
    int m = mat[0].size();
    while (!q.empty())
    {
        int t = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;
            if (isPossible(nrow, n, ncol, m) && vis[nrow][ncol] == -1 && (mat[nrow][ncol] != yeastColor))
            {
                q.push({t + 1, {nrow, ncol}});
                vis[nrow][ncol] = t + 1;
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<int>> vis1(n, vector<int>(m, -1));
    vector<vector<int>> vis2(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
            {
                vis1[i][j] = 0;
                q.push({0, {i, j}});
            }
        }
    }

    bfs(mat, vis1, q, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 2)
            {
                vis2[i][j] = 0;
                q.push({0, {i, j}});
            }
        }
    }

    bfs(mat, vis2, q, 2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis1[i][j] == vis2[i][j])
                cout << "3";
            else if (vis1[i][j] < vis2[i][j])
                cout << "1";
            else
                cout << "2";
        }
        cout << endl;
    }

    return 0;
}

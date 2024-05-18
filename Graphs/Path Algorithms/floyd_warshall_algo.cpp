#include <bits/stdc++.h>
using namespace std;

/*The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.*/

//Multisource shirtest Path
//Helps to detect negative cycle as well
//Go via every node/vertex
//Dynamic Programming Problem
//Adjacency matrix is used

//The nodes which can't be reached are initially given as infinity in the adjacency matrix

//If no negative cycles in graph, then you can apply Dijkstras algorithm in all nodes

void floydWarshall(vector<vector<int>>&matrix)
{
    int n = matrix.size();
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k]!=1e9 && matrix[k][j]!=1e9)
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    //Check for negative cycle
    for (int i = 0;i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            cout<<"Negative cycle exits"<<endl;
        }
    }
}
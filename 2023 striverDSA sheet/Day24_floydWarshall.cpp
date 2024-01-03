#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(int V, vector<vector<int>> matrix)
{
    // converting matrix to cost matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
    return matrix;
}

int main(int argc, char const *argv[])
{
    return 0;
}

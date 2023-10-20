#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m; // m number of edges and n number of nodes
    vector<vector<int>> adjm(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjm[x][y] = adjm[y][x] = 1;
    }
    cout << "Adjacency matrix : " << endl;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << adjm[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << "Adjacency List: " << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << i << "->";
        for (int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
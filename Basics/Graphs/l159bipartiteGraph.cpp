#include <bits/stdc++.h>
using namespace std;

// Algorithm
/*
1. Traverse the graph
2. If the current node is of red color, paint its neighbors as blue
If you are able to color the graph successfully, then the graph is colored
*/
vector<vector<int>> adj;
vector<int> col;
vector<bool> vis;
bool bipartite;

void color(int i, int clr)
{
    if (col[i] != -1 and col[i] != clr)
    {
        bipartite = false;
        return;
    }
    col[i] = clr;
    if (vis[i])
        return;
    vis[i] = true;
    for (auto j : adj[i])
    {
        color(j, clr xor 1);
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    bipartite = true;

    adj = vector<vector<int>>(n + 1);
    col = vector<int>(n, -1);
    vis = vector<bool>(n, false);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n ; i++)
    {
        if (col[i] == -1) // if graph is uncolored
        {
            color(i, 0); // color it with red
        }
    }

    if (bipartite)
    {
        cout << "Graph is bipartite" << endl;
    }
    else
    {
        cout << "Graph is not bipartite" << endl;
    }

    return 0;
}

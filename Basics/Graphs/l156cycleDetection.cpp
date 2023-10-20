#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[src] = true;
    for (auto i : adj[src])
    {
        if (i != parent)
        {
            if (visited[i])
                return true;
            if (!visited[i] and isCycle(i, adj, visited, src))
                return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, m; // n : node and m : edge
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool cycle = false;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] and isCycle(i, adj, visited, -1))
        {
            cycle = true;
        }
    }
    if (cycle)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle is not present" << endl;
    return 0;
}
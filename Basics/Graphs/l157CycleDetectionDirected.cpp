#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack)
{
    stack[src] = 1;
    if (!visited[src])
    {
        visited[src] = true;
        for (auto i : adj[src])
        {
            if (!visited[i] and isCycle(i, adj, visited, stack))
            {
                return true;
            }
            if (stack[i])
                return true;
        }
    }
    stack[src] = 0;
    return false;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int x, y; // x--->y
        cin >> x >> y;
        adj[x].push_back(y);
    }
    bool cycle = false;
    vector<bool> visited(n, false);
    vector<int> stack(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] and isCycle(i, adj, visited, stack))
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
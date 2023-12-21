#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &col, int color)
{
    col[node] = color;

    for (auto a : adj[node])
    {
        if (col[a] == -1)
        {
            if (dfs(a, adj, col, !col[node]) == false)
                return false;
        }
        else if (col[a] == col[node])
            return false;
    }
    return true;
}

bool isBipartite(int v, vector<int> adj[])
{
    vector<int> col(v, -1);

    for (int i = 0; i < v; i++)
    {
        if (col[i] == -1)
        {
            if (dfs(i, adj, col, 0) == false)
                return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    return 0;
}

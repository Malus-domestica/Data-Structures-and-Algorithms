#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, int parent, vector<int> &vis)
{
    vis[node] = 1;

    for (auto a : adj[node])
    {
        if (!vis[a])
        {
            if (dfs(a, adj, node, vis))
                return true;
        }
        else if (a != parent)
            return true;
    }
    return false;
}

bool isCycle(int v, vector<vector<int>> adj[])
{
    vector<int> vis(v, 0);
    // return dfs(1,adj,-1,vis);

    for (int i = 0; i < v; i++)
        if (!vis[i])
            if (dfs(i,adj,-1,vis))
                return true;
    return false;
}

int main(int argc, char const *argv[])
{
    return 0;
}

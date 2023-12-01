#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &dfs, vector<int> &vis, vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!vis[i] and dfs(adj[node][i], adj, vis, dfsVis))
            return true;
        else if (dfsVis[adj[node][i]])
            return true;
    }
    dfsVis[node] = 0;
    return false;
}

bool isCycle(int v, vector<vector<int>> adj)
{
    vector<int> vis(v, 0);
    vector<int> dfsVis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i] and dfs(node, adj, vis, dfsVis))
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &s)
{
    vis[node] = 1;

    for (auto a : adj[node])
    {
        if (!vis[a])
            dfs(a, adj, vis, s);
    }
    s.push(node);
}

vector<int> topoSort(int v, vector<int> adj[])
{
    vector<int> vis(v,0);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, s);
    }
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}

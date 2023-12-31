#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
bool vis[N];
vector<int> adj[N];

void dfs(int node)
{
    // preorder
    vis[node] = true;
    
    // inorder
    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!vis[*it])
            dfs(*it);
    }
    //postorder
    cout << node << " ";
}

int main(int argc, char const *argv[])
{
    int n, m; // number of nodes and number of edges
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        vis[i] = 0;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // cout<<""
    dfs(1);
    return 0;
}

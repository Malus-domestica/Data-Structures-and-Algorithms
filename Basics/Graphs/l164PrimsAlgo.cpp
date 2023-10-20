#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int n, m;
// vector<vector<pair<int, int>>> g;
vector<vector<int>> g[N];
int cost = 0;
vector<int> dist(N), parent(N);
vector<bool> vis(N, false);

void primsMST(int source)
{
    for (int i = 1; i < n; i++) // dist of curr source node from all nodes is inf initially
    {
        dist[i] = INT_MAX;
    }
    set<vector<int>> s;    // set to insert edges and wt
    dist[source] = 0;      // distance of node from itself is 0
    s.insert({0, source}); //{wt, vertex}
    while (!s.empty())
    {
        auto x = *(s.begin()); // extract top element from set
        s.erase(x);
        vis[x[1]] = true;      // mark the visited node
        int u = x[1];
        // int v = parent[x[1]];
        int w = x[0];
        // cout << u << " ---> " << v << "   " << w << endl;
        cost += w;
        for (auto it : g[u])
        {
            if (vis[it[0]])
                continue;
            if (dist[it[0]] > it[1])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u, v, w;
        cout << "CHECK" << endl;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        // parent[u] = v;
    }
    primsMST(0); // calls prim's mst with vertex 0
    cout << cost << endl;
    return 0;
}

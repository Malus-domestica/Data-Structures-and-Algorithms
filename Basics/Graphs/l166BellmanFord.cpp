#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges; // u,v,w
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;
    vector<int> dist(n, INF); // starts from node 0
    dist[src] = 0;
    // cout << "CHECK" << endl;
    // cout << edges[0][0] << endl;
    for (int it = 0; it < n - 1; it++)
    {
        for (auto e : edges)
        {
            int u, v, w;
            // cout << "CHECK" << endl;
            // cout << e[0] << endl;
            u = e[0];
            v = e[1];
            w = e[2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << "   ";
    }
    cout << endl;
    return 0;
}

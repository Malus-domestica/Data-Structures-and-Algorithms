#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt; // u--->v wt
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    int source;
    cin >> source;   
    set<pair<int, int>> s; // set to store nodes and dist
    vector<int> dist(n + 1, inf);
    //{wt, node->num}:- this pattern is preferred because set is sorted on the basis of first member of elements
    dist[source] = 0;
    s.insert({0, source});
    while (!s.empty())
    {
        auto node = *(s.begin());
        s.erase(node);
        for (auto it : graph[node.second])
        {
            if (dist[node.second] + it.second < dist[it.first])
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[node.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
    for (int i = 1; i < dist.size(); i++)
    {
        if(dist[i]<inf)
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}

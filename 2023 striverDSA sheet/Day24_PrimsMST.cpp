#include <bits/stdc++.h>
using namespace std;

int primsMST(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>> greater<pair<int, int>>> pq;
    // here we are not storing parent because only sum of edges is asked not mst
    pq.push({0, 0}); //{wt,src}
    int sum = 0;
    vector<int> vis(V, 0);
    while (!pq.empty())
    {
        auto ele = pq.top();
        int wt = ele.first;
        int node = ele.second;
        pq.pop();
        if (vis[node])
            continue;
        sum += wt;
        for (auto a : adj[node])
        {
            int adjNode = a[0];
            int edge = a[1];
            if (!vis[adjNode])
                pq.push({edge, adjNode});
        }
    }
    return wt;
}

int main(int argc, char const *argv[])
{
    return 0;
}

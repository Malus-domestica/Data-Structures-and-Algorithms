#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, vector<vector<int>> adj, int v)
{
    // total number of vertices
    // src is source node i.e node from where all shortest path will be calculated to all other nodes

    vector<int> dis(v, 1e9); // initialise all distances with infinity

    // minHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto ele = pq.top();
        int dist = ele[0];
        int node = ele[1];
        pq.pop();

        for (auto it : adj[node])
        {
            int edgeWeight = it[1];
            int adjNode = it[0];
            if (dist + edgeWeight < dis[adjNode])
            {
                dis[adjNode] = dist + edgeWeight;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }

    return dis;
}

int main(int argc, char const *argv[])
{
    return 0;
}

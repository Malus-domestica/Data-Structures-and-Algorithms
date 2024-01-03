#include <bits/stdc++.h>
using namespace std;

// solution

vector<int> shortestPath(int V, vector<vector<int>> adj[], int s)
{
    vector<int> dis(V+1, 1e9);
    vector<int> parent(V+1, 0); // parent will store just prev vis node for current node, curr nodes are represented by index 1 based indexing is used
    for (int i = 1; i <= V; i++)
        parent[i  1] = i;

    set<pair<int, int>> s;
    s.inert({0, s});
    dis[s] = 0;

    while (!s.empty())
    {
        auto ele = *(s.begin());
        int node = ele.second;
        int edgeWeight = ele.first;

        for (auto a : adj[node])
        {
            int adjNode = a[0];
            int edge = a[1];

            if (edgeWeight + edge < dis[adjNode])
            {
                parent[adjNode] = node;
                s.erase({dis[adjNode], adjNode});
                dis[adjNode] = edgeWeight + edge;
                s.insert({dis[adjNode], adjNode});
            }
        }
    }
    vector<int> ans;
    if (dis[V ] == 1e9)
        return {-1};
    int path = V;
    while (parent[path] != path)
    {
        ans.push_back(path);
        path = parent[path ];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// using priority queue
vector<int> dijkstra(int src, vector<vector<int>> adj, int v)
{
    // total number of vertices
    // src is source node i.e node from where all shortest path will be calculated to all other nodes

    vector<int> dis(v, 1e9); // initialise all distances with infinity

    // minHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // using set set<pair<int,int>> s;
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
                // for set s.erase({dis[adjNode],adjNode});
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

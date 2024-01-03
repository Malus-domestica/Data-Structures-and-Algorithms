#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> edges, int s)
{
    vector<int> dis(V + 1, 1e9);
    dis[s] = 0;
    int isCycle = 0;
    for (int i = 1; i <= V; i++)
    {
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if (dis[u] != 1e9 and dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                if (i == V  )
                    isCycle = 1; // if there is cycle edges will update even after (v-1)th iteration
            }
        }
    }
    vector<int> ans(V + 1, -1);
    if (isCycle)
        return ans;
    return dis;
}

int main(int argc, char const *argv[])
{

    return 0;
}

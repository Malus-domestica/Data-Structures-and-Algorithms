#include <bits/stdc++.h>
using namespace std;

bool isCycle(int v, vector<vector<int>> adj)
{
    // calculate indeg
    vector<int> indeg(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto a : adj[i])
        {
            indeg[a]++;
        }
    }

    queue<int> q;
    vector<int> topoSort;

    // insert all the elements with indeg 0
    for (int i = 0; i < indeg.size(); i++)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        auto ele = q.front();
        topoSort.push_back(ele);
        q.pop();

        for (auto a : adj[ele])
        {
            indeg[a]--;
            if (indeg[a] == 0)
                q.push();
        }
    }
    if (q.empty() and topoSort.size() < v)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    return 0;
}

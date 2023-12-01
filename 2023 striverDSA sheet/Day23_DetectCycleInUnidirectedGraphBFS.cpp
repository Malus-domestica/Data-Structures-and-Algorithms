#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj_list(numCourses);
        queue<int> q;
        vector<int> ans;

        for (auto a : prerequisites)
        {
            adj_list[a[1]].push_back(a[0]);
            indeg[a[0]]++;
        }
        cout << indeg.size() << endl;

        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            ans.push_back(a);
            for (auto e : adj_list[a])
            {
                indeg[e]--;
                if (indeg[e] == 0)
                    q.push(e);
            }
        }
        cout << ans.size() << endl;
        return ans.size() == numCourses;
    }
};

// #according to video

bool detect(int src, vector<vector<int>> &adj, vector<int> &vis)
{
    queue<pair<int, int>> q;
    q.push({src, -1}); //{child,parent}
    vis[src] = 1;

    while (!q.empty())
    {
        int child = q.front().first;
        int parent = q.front().second;

        q.pop();

        for (auto a : adj[child])
        {
            if (!vis[a])
            {
                vis[a] = 1;
                q.push({a, child});
            }
            else if (a != parent)
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> adj)
{
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            if (detect(i, adj, vis))
                return true;
    }
    return false;
}
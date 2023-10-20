#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> adj_list[n];
    vector<int> indegree(n, 0);
    // directed graphs
    for (int i = 0; i < m; i++)
    {
        int x, y; // x--->y
        cin >> x >> y;
        adj_list[x].push_back(y);
        indegree[y]++;
    }
    // push all elements whose indegree is zero
    queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        int x = pq.front();
        pq.pop();
        cout << x << "  ";
        // x-->y:- reduce indegree of all the connected edges
        for (auto it : adj_list[x])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                pq.push(it);
        }
    }
    cout << endl;
    return 0;
}

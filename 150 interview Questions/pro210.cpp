#include <bits/stdc++.h>
using namespace std;
// topological sort
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> ans={};
    int n = prerequisites.size();
    if (n == 0)
    {
        for (int i = 0; i < numCourses; i++)
            ans.push_back(i);
        return ans;
    }
    vector<int> indeg(numCourses, 0);
    vector<vector<int>> adj_list(numCourses);
    for (auto a : prerequisites)
    {
        adj_list[a[1]].push_back(a[0]);
        indeg[a[0]]++;
    }
    queue<int> pq;
    for (int i = 0; i < numCourses; i++)
    {
        if (indeg[i] == 0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        int e = pq.front();
        ans.push_back(e);
        pq.pop();
        for (int a : adj_list[e])
        {
            indeg[a]--;
            if (indeg[a] == 0)
                pq.push(a);
        }
    }
    vector<int> empty;
    return ans.size()==n?ans:empty;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> pre = {{1,0},{1,2},{0,1}};
    int numCourses = 3;
    vector<int> ans = findOrder(numCourses, pre);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}

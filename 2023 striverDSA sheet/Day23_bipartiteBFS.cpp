#include <bits/stdc++.h>
using namespace std;
//here its assumed this is not multi component graph
bool isBipartite(int v, vector<int> adj[])
{
    queue<int> q;
    vector<int> col(v, -1); //-1 not colored

    q.push(0);
    col[0] = 0;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        for (auto a : adj[node])
        {
            if (col[a] == -1) // adjacent node is yet colored
            {
                col[a] = !col[node]; // give the opposite color
                q.push(a);
            }
            //someone has already colored and it has same color as its current parent then its not bipartite
            else if (col[a] == col[node])
                return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    return 0;
}

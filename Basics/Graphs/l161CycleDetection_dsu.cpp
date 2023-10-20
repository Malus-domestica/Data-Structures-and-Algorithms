#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

vector<int> parent(N);
vector<int> sz(N);
// dsu:- disjoint set union
void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
    {
        make_set(i);
    }
    int n, m; // n:nodes and m:edges
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    // cycle detection
    bool cycle = false;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y)
        {
            cycle = true;
            break;
        }
        else
        {
            union_set(u, v);
        }
    }
    if (cycle)
        cout << "Cycle in present" << endl;
    else
        cout << "Cycle is absent" << endl;
    return 0;
}

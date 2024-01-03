#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
vector<int> parent(N);
vector<int> sz(N);
// dsu:- disjoint set union
void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1; // to reduce long chains
}

// tc:- log(N) will be the height of tree after compression
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // path compression
}

void union_set(int a, int b)
{
    a = find_set(a); // returns parent of each
    b = find_set(b); // returns parent of each
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
// tc of disjoint set union is O(1)
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
        int w, x, y;
        cin >> x >> y >> w;
        edges.push_back({w, x, y});
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto i : edges)
    {
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y)
        {
            continue;
        }
        else
        {
            cost += i[0];
            cout << u << " ---> " << v << endl;
            union_set(u, v);
        }
    }
    cout << cost << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> adj[N];
vector<bool> vis(N, false);
void dfs(int i)
{
    // preorder
    if (!vis[i])
        vis[i] = true;
    cout << i << "  ";
    // inorder
    vector<int>::iterator it;
    for (it = adj[i].begin(); it != adj[i].end(); it++)
    {
        if (!vis[*it])
            dfs(*it);
    }
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m; // n : number of node and m: number of edges
    // vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y; // x---->y
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << " Adjacency mat: " << endl;
    for (int k = 0; k < n + 1; k++)
    {
        cout << k << " : ";
        for (int l = 0; l < adj[k].size(); l++)
            cout << adj[k][l] << " ";
        cout << endl;
    }
    cout << endl;
    int count = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (!vis[i])
        {
            cout << i << "  :  ";
            dfs(i);
            cout << endl;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> color(n+1, -1); // 0:red, 1:blue and -1:uncolored
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cout << "Color of x: " << color[x] << "  ||  "
                 << "Color of y: " << color[y] << endl;
        // case 1 when both are not colored
        if (color[x] == -1 and color[y] == -1)
        {
            color[x] = 0; // red
            color[y] = 1; // blue
        }
        else if ((color[x] == 0 or color[x] == 1) and color[y] == -1)
        {
            color[y] = color[x] ^ 1; // opposite color
        }
        else if ((color[y] == 0 or color[y] == 1) and color[x] == -1)
        {
            color[x] = color[y] ^ 1; // opposite color
        }
        else if (color[x] == color[y])
        {
            cout << "Not bipartite graph" << endl;
            return 0;
        }
    }
    cout << "Graph is bipartite" << endl;
    // traverse the graph

    return 0;
}

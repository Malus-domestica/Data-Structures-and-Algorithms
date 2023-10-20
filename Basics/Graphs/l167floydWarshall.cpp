#include <bits/stdc++.h>
using namespace std;
const int INF = 1e7;
int main(int argc, char const *argv[])
{
    vector<vector<int>> adj = {{0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}};
    int n = adj.size();
    vector<vector<int>> dist = adj;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cout << "\n Relaxed distances: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dist[i][j]==INF)
            cout<<-1<<" ";
            else
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

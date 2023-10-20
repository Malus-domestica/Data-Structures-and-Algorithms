#include <bits/stdc++.h>
using namespace std;
// 200. Number of Islands
//connected components
void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int delcol = -1; delcol <= 1; delcol++)
        {
            int neighbourRow = row ;
            int neighbourCol = col + delcol;
            if (neighbourRow >= 0 and neighbourRow < n and neighbourCol >= 0 and neighbourCol < m and grid[neighbourRow][neighbourCol] == '1' and !vis[neighbourRow][neighbourCol])
            {
                vis[neighbourRow][neighbourCol] = 1;
                q.push({neighbourRow, neighbourCol});
            }
        }
        for (int delrow = -1; delrow <= 1; delrow++)
        {
            int neighbourRow = row + delrow;
            int neighbourCol = col ;
            if (neighbourRow >= 0 and neighbourRow < n and neighbourCol >= 0 and neighbourCol < m and grid[neighbourRow][neighbourCol] == '1' and !vis[neighbourRow][neighbourCol])
            {
                vis[neighbourRow][neighbourCol] = 1;
                q.push({neighbourRow, neighbourCol});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] and grid[row][col] == '1')
            {
                cnt++;
                cout << "hello" << endl;
                bfs(row, col, vis, grid);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << vis[i][j] << "  ";
        cout << endl;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid) << endl;
    return 0;
}

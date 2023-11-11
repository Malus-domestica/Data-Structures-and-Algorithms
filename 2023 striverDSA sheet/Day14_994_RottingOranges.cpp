#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        int fresh = 0;
        // find starting points
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        while (!q.empty() and fresh > 0)
        {
            int len = q.size();
            for (int k = 0; k < len; k++)
            {
                auto p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                // push neighbors
                // left
                if (j > 0 and grid[i][j - 1] == 1)
                {
                    q.push({i, j - 1});
                    fresh--;
                    grid[i][j - 1] = 2;
                }
                // right
                if (j + 1 < m and grid[i][j + 1] == 1)
                {
                    q.push({i, j + 1});
                    fresh--;
                    grid[i][j + 1] = 2;
                }
                // top
                if (i > 0 and grid[i - 1][j] == 1)
                {
                    q.push({i - 1, j});
                    fresh--;
                    grid[i - 1][j] = 2;
                }
                // bottom
                if (i + 1 < n and grid[i + 1][j] == 1)
                {
                    q.push({i + 1, j});
                    fresh--;
                    grid[i + 1][j] = 2;
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
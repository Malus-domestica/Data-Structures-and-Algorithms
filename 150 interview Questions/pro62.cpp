#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    cout << "hello" << i << j << endl;
    if (i == m - 1 and j == n - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int r = 0, b = 0;
    if (i < m)
    {
        b = func(i + 1, j, m, n, dp);
    }
    if (j < n)
    {
        r = func(i, j + 1, m, n, dp);
    }
    return dp[i][j] = (r + b);
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector(n + 1, -1));

    // base case
    for (int i = 0; i < m; i++)
        dp[i][n - 1] = 1;
    for (int j = 0; j < n; j++)
        dp[m - 1][j] = 1;

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            int r = 0, b = 0;
            if (i < m)
            {
                b = dp[i + 1][j];
            }
            if (j < n)
            {
                r = dp[i][j + 1];
            }
            dp[i][j] = (r + b);
        }
    }

    return dp[0][0];
}

int main(int argc, char const *argv[])
{
    cout << uniquePaths(3, 7) << endl;
    return 0;
}

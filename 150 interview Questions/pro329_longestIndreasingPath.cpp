#include <bits/stdc++.h>
using namespace std;

int dfs(int r, int c, int preVal, vector<vector<int>> &matrix, int n, int m,vector<vector<int>> &dp)
{
    if (r < 0 or c < 0 or r == n or c == m or matrix[r][c] <= preVal)
        return 0;
    if (dp[r][c] != -1)
        return dp[r][c];
    int res = 1;
    res = max(res, 1 + dfs(r + 1, c, matrix[r][c], matrix, n, m,dp));
    res = max(res, 1 + dfs(r - 1, c, matrix[r][c], matrix, n, m,dp));
    res = max(res, 1 + dfs(r, c + 1, matrix[r][c], matrix, n, m,dp));
    res = max(res, 1 + dfs(r, c - 1, matrix[r][c], matrix, n, m,dp));
    dp[r][c] = res;
    return res;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector(m + 1, -1));
    int mxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mxLen = (mxLen, dfs(i, j, -1, matrix, n, m));
        }
    }
    return mxLen;
}

int main(int argc, char const *argv[])
{
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> arr, vector<vector<int>> &dp)
{
    if (i == j)
        return dp[i][j] = 0;
    int mini = 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    for (int k = i; k <= j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + (f(i, k, arr,dp) + f(k + 1, j, arr,dp));
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {};
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector(n + 1, -1));
    int ans = f(1, n - 1, arr, dp);
    return 0;
}

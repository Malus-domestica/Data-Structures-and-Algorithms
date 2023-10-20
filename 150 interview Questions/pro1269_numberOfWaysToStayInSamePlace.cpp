#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int M = 1e9 + 7;
    int f(int i, int cnt, int n, int step, vector<vector<int>> &dp)
    {
        if (i < 0 or i >= n or cnt > step)
            return 0;
        if (cnt == step and i == 0)
            return 1;
        // cout<<"hello"<<endl;
        if (dp[i][cnt] != -1)
            return dp[i][cnt];
        long l = (f(i - 1, cnt + 1, n, step, dp)) % M;
        long r = (f(i + 1, cnt + 1, n, step, dp)) % M;
        int s = (f(i, cnt + 1, n, step, dp)) % M;

        return dp[i][cnt] = ((l + r) % M + s) % M;
    }
    int numWays(int steps, int arrLen)
    {
        arrLen = min(steps, arrLen);
        vector<vector<int>> dp(arrLen + 1, vector(steps + 1, -1));
        int ans = (f(0, 0, arrLen, steps, dp));
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

int funct(int i, int t,vector<vector<int>> &dp)
{
    // cout << i << " " << t << endl;
    if (i * i == t)
        return 1;

    if (i == 0 and t != 0)
        return 0;
    if(dp[i][t]!=-1) return dp[i][t];
    int take = INT_MAX, not_take;
    if (i * i < t)
        take = 1 + funct(i, t - (i * i),dp);
    not_take = 0 + funct(i - 1, t,dp);
    // cout << take << "  " << not_take << endl;
    if (take == 0)
        return dp[i][t] = not_take;
    else if (not_take == 0)
        return dp[i][t] =  take;
    return dp[i][t] = min(take, not_take);
}
int numSquares(int n)
{
    int temp = n;
    int sqr = floor(sqrt(n));
    vector<vector<int>> dp(sqr+1, vector(n+1,-1));
    // cout << sqr << endl;
    int cnt = funct(sqr, n,dp);
    return cnt;
}
int main(int argc, char const *argv[])
{
    cout << numSquares(308) << endl;
    return 0;
}

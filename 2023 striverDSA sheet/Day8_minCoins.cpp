#include <bits/stdc++.h>
using namespace std;

int funct(int i, vector<int> &coins, int t, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (t % coins[i] == 0)
            return dp[i][t] = t / coins[i];
        else
            return 1e9;
    }
    int take = 1e9, not_take;
    if (dp[i][t] != -1)
        return dp[i][t];
    if (coins[i] <= t)
        take = 1 + funct(i, coins, t - coins[i], dp);
    not_take = funct(i - 1, coins, t, dp);
    return dp[i][t] = min(take, not_take);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    return funct(n - 1, coins, amount, dp) != 1e9 ? funct(n - 1, coins, amount, dp) : -1;
}

int main(int argc, char const *argv[])
{
    vector<int> coins = {2};
    cout << coinChange(coins, 3) << endl;
    return 0;
}

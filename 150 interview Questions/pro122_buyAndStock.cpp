#include <bits/stdc++.h>
using namespace std;

int calc(int i, int isBuy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == prices.size())
        return 0;
    int profit;
    if (dp[i][isBuy] != -1)
        return dp[i][isBuy];
    if (isBuy)
    {
        profit = max(-prices[i] + calc(i + 1, 0, prices, dp), 0 + calc(i + 1, 1, prices, dp));
    }
    else
    {
        profit = max(prices[i] + calc(i + 1, 1, prices, dp), 0 + calc(i + 1, 0, prices, dp));
    }
    return dp[i][isBuy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector(3, 0));
    int profit;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int isBuy = 1; isBuy >=0; isBuy--)
        {
            if (isBuy)
            {
                profit = max(-prices[i] + dp[i + 1][0],  dp[i + 1][1]);
            }
            else
            {
                profit = max(prices[i] + dp[i + 1][1], dp[i+1][0]);
            }
            dp[i][isBuy] = profit;
        }
    }
    return dp[0][1];
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << maxProfit(nums) << endl;
    return 0;
}

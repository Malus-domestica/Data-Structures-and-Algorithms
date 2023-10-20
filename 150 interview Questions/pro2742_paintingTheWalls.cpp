class Solution
{
public:
    int f(int i, int rem, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp)
    {
        if (rem <= 0)
            return 0;
        if (i == cost.size())
            return 1e9;
        if (dp[i][rem] != -1)
            return dp[i][rem];
        int take = cost[i] + f(i + 1, rem - 1 - time[i], cost, time, dp);
        int not_take = f(i + 1, rem, cost, time, dp);

        return dp[i][rem] = min(take, not_take);
    }
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector(n + 1, -1));
        return f(0, n, cost, time, dp);
    }
};
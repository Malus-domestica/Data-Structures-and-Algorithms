#include <bits/stdc++.h>
using namespace std;
/*
int rob(vector<int> &nums)
{
    int o = 0, e = 0;
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        // cout << nums[i] << " ";
        e += nums[i];
        i = i + 2;
    }
    i = 1;
    // cout << endl;
    while (i < n)
    {
        // cout << nums[i] << " ";
        o += nums[i];
        i = i + 2;
    }
    return max(o, e);
}
*/

int funct(int i, vector<int> &nums, int n, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int take = nums[i] + funct(i + 2, nums, n, dp);
    int not_take = funct(i + 1, nums, n, dp);
    return dp[i] = max(take, not_take);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 2, -1);
    // funct(0, nums, n, dp);
    int take, not_take;
    dp[n] = 0;
    dp[n + 1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        take = nums[i] + dp[i + 2];
        not_take = dp[i + 1];
        dp[i] = max(take, not_take);
    }
    return dp[0];
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums) << endl;
    return 0;
}

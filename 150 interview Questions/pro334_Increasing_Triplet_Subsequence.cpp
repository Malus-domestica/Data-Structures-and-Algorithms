#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> nums, int prev_ind, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return 0;
    int len = 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    // not take
    len = 0 + f(ind + 1, nums, prev_ind,dp);

    // take
    if (prev_ind == -1 or nums[ind] > nums[prev_ind])
        len = max(len, 1 + f(ind + 1, nums, ind,dp));
    return dp[ind][prev_ind + 1] = len;
}

bool increasingTriplet(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector(n + 1, -1));
    // int len = f(0, nums, -1,dp);



    if (len >= 3)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 1, 5, 0, 4, 6};
    cout << increasingTriplet(nums) << endl;
    return 0;
}

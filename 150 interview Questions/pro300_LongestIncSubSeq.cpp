#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = dp[ind + 1][prev_ind + 1];
            if (prev_ind == -1 or nums[ind] > nums[prev_ind])
            {
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }
            dp[ind][prev_ind+1] = len;
        }
    }
    return dp[0][0];
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {7,7,7,7,7,7,7};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}

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
            int len = dp[ind + 1][prev_ind + 1];//not take
            if (prev_ind == -1 or nums[ind] > nums[prev_ind])
            {
                len = max(len, 1 + dp[ind + 1][ind + 1]);//take
            }
            dp[ind][prev_ind + 1] = len;
        }
    }
    return dp[0][0];
}
int N;
vector<int> arr[N];
vector<vector<int>> dp[N+1][N+1];//init with -1
int f(int ind, int prev_ind)
{
    if(ind  == N) return dp[ind][prev_ind+1] = 0;
    if(dp[ind][prev_ind+1] !=-1) return dp[ind][prev_ind]
    int len = 0 + f(ind + 1, prev_ind); // not take
    if (prev_ind == -1 or arr[ind] > arr[prev_ind + 1])
        len = max(len ,1 + f(ind + 1, ind));
    return dp[ind][prev_ind+1] = len;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}

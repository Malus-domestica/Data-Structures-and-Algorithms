#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int> &arr, vector<int> &dp)
{
    if (i >= arr.size() - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MAX;
    for (int j = 1; j <= 3; j++)
    {
        if (j + i < arr.size())
            ans = min(ans, f(j + i, arr, dp) + abs(arr[i] - arr[j + i]));
    }
    return dp[i] = ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {30, 10, 60, 10, 60};
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    int ans = f(0, nums, dp);

    cout << ans << endl;
    return 0;
}
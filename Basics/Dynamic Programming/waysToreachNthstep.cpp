#include <bits/stdc++.h>
using namespace std;
vector<int> dp(100, 0);

// bottom to top approach is followed here
// int count_ways_to_reach(vector<int> stk, int sum, int k)
// {
//     cout << "Hello" << endl;
//     if (sum == k)
//         return 1;
//     else if (sum > k)
//         return 0;

//     stk.push_back(1);
//     sum += 1;
//     int l = count_ways_to_reach(stk, sum, k);
//     stk.pop_back();
//     stk.push_back(2);
//     sum -= 1;
//     sum += 2;
//     int r = count_ways_to_reach(stk, sum, k);
//     return r + l;
// }

// top to bottom approach is followed here (index)
// int count_ways_to_reach(int idx)
// {
//     if (idx == 0)
//         return 1;
//     if (idx == 1)
//         return 1;
//     int l = count_ways_to_reach(idx - 1);
//     int r = count_ways_to_reach(idx - 2);
//     return l + r;
// }

int count_ways_to_reach(int idx)
{
    if (idx == 0)
        return dp[0];
    if (idx == 1)
        return dp[1];
    int l = count_ways_to_reach(idx - 1);
    int r = count_ways_to_reach(idx - 2);
    dp[idx] = l + r;
    return l + r;
}

int main(int argc, char const *argv[])
{
    // vector<int> stk = {};
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    // cout << count_ways_to_reach(n) << endl;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
    return 0;
}

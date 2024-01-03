#include <bits/stdc++.h>
using namespace std;

int f(int i1, int i2, vector<vector<int>> &dp, string text1, string text2)
{
    if (i1 < 0 or i2 < 0)
        return 0;
    if (text1[i1] == text2[i2]) // match
        return dp[i1][i2] = 1 + f(i1 - 1, i2 - 1, dp, text1, text2);
    // not match
    return dp[i1][i2] = max(f(i1 - 1, i2, dp, text1, text2), f(i1, i2 - 1, dp, text1, text2));
}

int main(int argc, char const *argv[])
{
    int n, m;
    vector<vector<int>> dp(n, vector(m, -1));

    return 0;
}

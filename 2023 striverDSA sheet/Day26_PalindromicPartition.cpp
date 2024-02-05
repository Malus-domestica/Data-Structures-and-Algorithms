#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int mincost(int i, int n, string str)
{
    if (i == str.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int cost = INT_MAX;
    int temp = "";
    for (int j = i; j < n; j++)
    {
        temp += str[i];
        if (isPalindrome(i, j, str))
        {
            cost = min(cost, 1 + mincost(j + 1, n, str));
        }
    }
    return dp[i] = cost;
}

int main(int argc, char const *argv[])
{
    string str = "";
    vector<vector<int>> dp(n + 1, vector(n + 1, -1));
    int ans = mincost(0, str.size(), str) - 1;
    return 0;
}

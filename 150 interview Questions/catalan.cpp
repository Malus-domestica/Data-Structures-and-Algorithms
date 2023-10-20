#include <bits/stdc++.h>
using namespace std;

int catalan(int n)
{
    if (n == 0 or n == 1)
        return 1;

    int sum = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        sum += catalan(i) * catalan(n - i - 1);
    }
    return sum;
}

int catalanDP(int n, vector<int> dp)
{
    if (n == 0 or n == 1)
        return dp[n] = 1;
    int sum = 0;
    if (dp[i != -1])
        return dp[i];
    for (int i = 0; i < n; i++)
    {
        sum += catalanDP(i) * catalanDP(n - i - 1)
    }
    return dp[n] = sum;
}

int main(int argc, char const *argv[])
{
    return 0;
}

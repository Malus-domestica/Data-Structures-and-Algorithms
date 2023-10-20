#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
vector<int> dp(N);

// method 1:-
//  vector<int> dp(N, -1);

// int fib(int n)
// {
//     if (n == 0)
//         return 0;
//     if (n == 1)
//         return 0;
//     if (n == 2)
//         return 1;
//     if (dp[n] != -1) // to eliminate overlapping
//         return dp[n];
//     dp[n] = fib(n - 1) + fib(n - 2);
//     return dp[n];
// }

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
    return 0;
}

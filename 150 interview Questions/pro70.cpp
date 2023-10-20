#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    if(n<=1) return n;
    int pre1 = 1, pre2 = 1;
    int ans;
    for (int i = 1; i < n; i++)
    {
        ans = pre1 + pre2;
        pre1 = pre2;
        pre2 = ans;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 1;
    cout << climbStairs(n) << endl;
    return 0;
}

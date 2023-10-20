#include <bits/stdc++.h>
using namespace std;

double funct(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    double ans;
    if (n % 2 != 0)
        ans = funct(x, n / 2) * funct(x, n / 2) * x;
    else
        ans = funct(x, n / 2) * funct(x, n / 2);
    return ans;
}

double myPow(double x, int n)
{
    if (n < 0)
    {
        x = 1 / x;
        n = n * -1;
    }
    return funct(x, n);
}

int main(int argc, char const *argv[])
{
    cout << myPow(2, -2) << endl;
    return 0;
}

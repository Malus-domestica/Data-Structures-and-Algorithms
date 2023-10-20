#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    if (x == INT_MIN)
        return 0;
    long long int rev_x = 0, rem;
    int flg = x < 0 ? -1 : 1;
    x = abs(x);
    cout << x << endl;
    while (x)
    {
        rem = x % 10;
        rev_x = rem + 10 * rev_x;
        if (rev_x >= INT_MAX)
            break;
        x /= 10;
    }
    cout << rev_x << endl;
    if (flg == -1)
    {
        if (-rev_x >= INT_MIN)
            return -rev_x;
    }
    if (flg == 1)
    {
        if (rev_x <= INT_MAX)
            return rev_x;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    cout << reverse(-2147483648) << endl;
    return 0;
}

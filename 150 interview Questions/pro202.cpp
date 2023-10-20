#include <bits/stdc++.h>
using namespace std;

int digitSquareSum(int n)
{
    int sum = 0, tmp;
    while (n)
    {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    int i = 0;
    do
    {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
        cout << slow << "  " << fast << endl;
        i++;
    } while (slow != fast);
    if (slow == 1)
        return 1;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    cout << isHappy(2) << endl;
    return 0;
}

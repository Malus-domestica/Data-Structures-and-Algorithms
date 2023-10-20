#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int rem;
    int temp;

    // make a containing bigger value
    if (b > a)
    {
        temp = a;
        a = b;
        b = temp;
    }

    while (b != 0)
    {
        rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}

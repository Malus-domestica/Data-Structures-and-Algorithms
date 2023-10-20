#include <iostream>
using namespace std;

int decToOct(int dec);

int main()
{
    cout << "Enter dec number" << endl;
    int dec;
    cin >> dec;
    cout << decToOct(dec) << endl;
    return 0;
}

int decToOct(int dec)
{
    int num = 0, q;
    int x = 1; // base
    while (x <= dec)
        x *= 8;
    x /= 8;
    while (x > 0)
    {
        q = dec / x;
        num = q + num * 10;
        dec -= q * x;
        x /= 8;
    }
    return num;
}
#include <iostream>
using namespace std;

int decToBin(int dec);

int main()
{
    cout << "Enter dec number" << endl;
    int dec;
    cin >> dec;
    cout << decToBin(dec) << endl;
    return 0;
}

int decToBin(int dec)
{
    int num = 0, q;
    int x = 1; // base
    while (x <= dec)
        x *= 2;
    x /= 2;
    while (x > 0)
    {
        q = dec / x;
        num = q + num * 10;
        dec -= q * x;
        x /= 2;
    }
    return num;
}
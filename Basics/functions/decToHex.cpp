#include <iostream>
using namespace std;

string decToHex(int dec);

int main()
{
    cout << "Enter dec number" << endl;
    int dec;
    cin >> dec;
    cout << decToHex(dec) << endl;
    return 0;
}

string decToHex(int dec)
{
    string num = "";
    char ch;
    int q;
    int x = 1; // base
    while (x <= dec)
        x *= 16;
    x /= 16;
    while (x > 0)
    {
        q = dec / x;
        if (q >= 10)
        {
            q += 55; // coverting to ascii value
            ch = (char)q;
        }
        else
        {
            q += 48;
            ch = (char)q;
        }
        num += ch;
        dec -= q * x;
        x /= 16;
    }
    return num;
}
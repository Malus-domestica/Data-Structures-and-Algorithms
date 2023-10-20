#include <iostream>
using namespace std;

void binToDec(string bin);

int main()
{
    cout << "Enter Binary number" << endl;
    string bin;
    cin >> bin;
    binToDec(bin);
    return 0;
}

void binToDec(string bin){
    int a, base, i, num = 0, len;
    len = bin.length();
    base = 1;
    i = len - 1;
    while (i >= 0)
    {
        a = (int)bin[i] - 48; // extracting number
        num += a * base;
        base *= 2;
        i--;
    }
    cout << num << endl;
}
#include <iostream>
using namespace std;

void octToDec(string bin);

int main()
{
    cout << "Enter Octal number" << endl;
    string bin;
    cin >> bin;
    octToDec(bin);
    return 0;
}

void octToDec(string bin){
    int a, base, i, num = 0, len;
    len = bin.length();
    base = 1;
    i = len - 1;
    while (i >= 0)
    {
        a = (int)bin[i] - 48; // extracting number
        num += a * base;
        base *= 8;
        i--;
    }
    cout << num << endl;
}
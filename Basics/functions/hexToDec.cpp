#include <iostream>
using namespace std;

int octToDec(string bin);

int main()
{
    cout << "Enter Hex number" << endl;
    string bin;
    cin >> bin;
    cout<<octToDec(bin)<<endl;
    return 0;
}

int octToDec(string bin)
{
    int a, base, i, num = 0, len;
    len = bin.length();
    base = 1;
    i = len - 1;
    while (i >= 0)
    {
        if ((int)bin[i] >= 48 && (int)bin[i] <= 57)
            a = (int)bin[i] - 48; // extracting number
        else{
            if ((int)bin[i] >= 97 && (int)bin[i] <= 102)
            a = (int)bin[i] - 87;
            else if((int)bin[i] >= 65 && (int)bin[i] <= 70)
            a = (int)bin[i] - 55;
        }
        num += a * base;
        base *= 16;
        i--;
    }
    return num;
}
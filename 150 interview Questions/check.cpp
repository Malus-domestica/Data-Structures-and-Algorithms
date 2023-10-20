#include <bits/stdc++.h>
using namespace std;

void printLine(string str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 97 and str[i] <= 122)
            cout << (char)toupper(str[i]);
        else
        {
            cout << endl;
            char c = tolower(str[i]);
            cout << c;
        }
    }
}

int main(int argc, char const *argv[])
{
    // string str = "hiHello";
    // getline(cin, str);
    // printLine(str);
    cout << -1 % 4 << endl;
    return 0;
}

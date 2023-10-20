#include <bits/stdc++.h>
using namespace std;

int minDiss(string str)
{
    int n = str.size();
    int diss = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '?')
        {
            if (i > 0)
            {
                cout << i << " ";
                str[i] = str[i - 1] == '0' ? '0' : '1';
            }
            else
            {
                if (i + 1 < n)
                {
                    if (str[i + 1] == '0')
                        str[i] = '0';
                    else if (str[i + 1] == '1')
                        str[i] = '1';
                    else
                        str[i] = '0';
                }
                else
                    str[i] = '0';
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (str[i] != str[i - 1])
            diss++;
    }
    return diss;
}
int main(int argc, char const *argv[])
{
    string str = "????";
    cout << str << endl;
    cout << minDiss(str) << endl;
    return 0;
}

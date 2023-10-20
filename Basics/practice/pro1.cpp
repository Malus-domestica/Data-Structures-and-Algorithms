#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    int n = str.length();
    int i = 0, j = n - 1, l, r;
    while (i < n)
    {
        l = i;
        j = n - 1;
        r = j;
        while (l < r)
        {
            if (str[l] == str[r])
            {
                l++, r--;
            }
            else
            {
                j--;
                r--;
                l = i;
            }
        }
    }
    return 0;
}

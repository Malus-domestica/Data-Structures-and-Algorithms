#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    // removing white spaces
    int pos, i = 0;
    while (s[i] == ' ')
        i++;
    

    // to get sign
    int flg = s[i] == '-' ? -1 : 1;
    // cout << flg << endl;
    if (s[i] == '-' or s[i] == '+')
        i++;

    s = s.substr(i);
    // cout<<s<<endl;
    i=0;

    // to get digits from s
    long long num = 0;
    while ((s[i] >= 48 and s[i] <= 57))
    {
        if (s[i] != ' ')
        {
            num = num * 10 + s[i] - 48;
        }
        i++;
    }
    // cout << num * flg << endl;

    if(num*flg<INT_MIN) return INT_MIN;
    if(num*flg>INT_MAX)return INT_MAX;

    return num*flg;
}

int main(int argc, char const *argv[])
{
    cout << myAtoi("41") << endl;
    return 0;
}

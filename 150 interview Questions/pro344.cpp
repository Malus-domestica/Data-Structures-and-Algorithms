#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
    int l = s.size();
    char temp;
    for (int i = 0; i < l / 2; i++)
    {
        temp = s[i];
        s[i] = s[l - 1 - i];
        s[l - 1 - i] = temp;
    }
}

int main(int argc, char const *argv[])
{
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for (auto e : s)
        cout << e;
    cout << endl;
    return 0;
}

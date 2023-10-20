#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();

    for (int i = 0; i < n; i++)
        tolower(s[i]);
    for (int j = 0; j < m; j++) 
        tolower(t[j]);
}

int main(int argc, char const *argv[])
{
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s)
{
    int n = s.size();
    int i = n - 1;
    while (i >= 0 and (s[i] < 65 or s[i] > 90) and (s[i] < 97 or s[i] > 122))
    {
        i--;
        cout << "hello" << endl;
    }
    int len = 0;
    while (i >= 0 and (s[i] >= 65 and s[i] <= 90) or (s[i] >= 97 and s[i] <= 122))
    {
        i--;
        len++;
    }
    return len;
}

int main()
{
    string s = "a";
    cout << lengthOfLastWord(s) << endl;
}
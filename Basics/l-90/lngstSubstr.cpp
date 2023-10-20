#include <bits/stdc++.h>
using namespace std;

// longest sub string without repeating character
int main(int argc, char const *argv[])
{
    string s;
    s = "bbbbb";
    vector<int> dict(256, -1);
    int maxlen = 0, start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxlen = max(maxlen, i - start);
    }
    cout << maxlen << endl;
    return 0;
}

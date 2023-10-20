#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    unordered_map<char, int> temp;
    ;
    for (auto e : s)
    {
        tolower(e);
        mp1[e]++;
    }
    for (auto e : t)
    {
        tolower(e);
        mp2[e]++;
    }
    if (mp1.size() < mp2.size())
    {
        temp = mp2;
        mp2 = mp1;
        mp1 = temp;
    }
    for (auto a : mp1)
    {
        cout << a.first << endl;
        if (mp2.find(a.first) == mp2.end() || a.second != mp2[a.first])
            return false;
    }
    return true;
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};

int main(int argc, char const *argv[])
{
    cout << isAnagram("a", "ab") << endl;
    return 0;
}

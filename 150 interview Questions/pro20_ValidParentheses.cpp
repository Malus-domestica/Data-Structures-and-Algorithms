#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> stk;
    unordered_map<char, char> mp;
    mp = {{')', '('}, {'}', '{'}, {']', '['}};

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stk.push(s[i]);
        else if (!stk.empty() and mp[s[i]] == stk.top())
            stk.pop();
        else
            return false;
    }
    if (stk.empty())
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    cout << isValid("]") << endl;
    return 0;
}

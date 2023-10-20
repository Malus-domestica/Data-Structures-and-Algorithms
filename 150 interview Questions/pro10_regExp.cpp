#include <bits/stdc++.h>
using namespace std;

bool f(int i, int j, string &pattern, string &text)
{
    if (i < 0 and j < 0)
        return true;
    if (i < 0 and j >= 0)
        return false;
    if (j < 0 and i >= 0)
    {
        for (int ii = 0; ii <= i; ii++)
        {
            if (pattern[ii] !+'*')
                return false;
        }
        return true;
    }
    if (pattern[i] == text[j] or pattern[i] == '?')
        return f(i + 1, j + 1, pattern, text);
    if (pattern[i] == '*')
        return f(i - 1, j, pattern, text) or f(i, j - 1, pattern, text);
    return false;
}

int main(int argc, char const *argv[])
{
    return 0;
}

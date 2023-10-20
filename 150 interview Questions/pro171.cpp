#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle)
{
    reverse(columnTitle.begin(), columnTitle.end());
    int base = 26;
    int ans = 0;
    for (int i = 0; i < columnTitle.size(); i++)
    {
        ans += (columnTitle[i] - 64) * pow(base, i);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << titleToNumber("A") << endl;
    return 0;
}

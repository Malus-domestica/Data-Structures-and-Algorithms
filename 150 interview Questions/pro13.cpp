#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int l= s.size();
    int ans=0;
    for(int i=0;i<l-1;i++)
    {
        if(mp[s[i]] < mp[s[i+1]]) ans -= mp[s[i]];
        else ans += mp[s[i]];
    }
    return ans+=mp[s[l-1]];
}

int main(int argc, char const *argv[])
{
    cout<<romanToInt("MCMXCIV")<<endl;
    return 0;
}

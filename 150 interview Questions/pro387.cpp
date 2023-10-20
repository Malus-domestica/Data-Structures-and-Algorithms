#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    int l = s.size();
    unordered_map<char, int> ind;
    unordered_map<char, int> freq;
    int j = 0;
    for (int i = 0; i < l; i++)
    {
        freq[s[i]]++;
        if (freq[s[i]] == 1)
        {
            ind[s[i]] = i;
            // cout << s[i] << "  " << i << endl;
        }
    }
    int ans = -1;
    for (auto e : freq)
    {
        // cout << e.first << "  " << ind[e.first] << endl;
        if (e.second == 1)
        {
            if (ans == -1)
                ans = ind[e.first];
            else ans=min(ans,ind[e.first]);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "loveleetcode";
    cout << firstUniqChar(s) << endl;
    return 0;
}

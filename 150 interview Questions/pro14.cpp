#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    for(int i=0;i<strs.size();i++){
        cout<<strs[i]<<" ";
    }
    int a = strs.size();
    string n = strs[0], m = strs[a - 1], ans = "";
    // cout << strs[1] << "  " << m << endl;
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == m[i])
        {
            ans += n[i];
        }
        else
            break;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> str = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(str) << endl;
    return 0;
}

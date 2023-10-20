#include <bits/stdc++.h>
using namespace std;

// bool f(int i, string s, vector<string> &wordDict, vector<int> &dp)
// {
//     // cout << i << " " << s.size() << endl;
//     if (i == s.size())
//         return true;
//     bool ans = false;
//     if (dp[i] != -1)
//         return dp[i];
//     for (auto w : wordDict)
//     {
//         int k = i, n = w.size(), j = 0;
//         for (j = 0; j < n; j++)
//         {
//             // cout << w[j] << " ";
//             if (s[k++] != w[j])
//                 break;
//         }
//         // cout << endl;
//         if (j == n)
//         {
//             // i = i + n;
//             cout << w << " " << i << endl;
//             ans = f(i + n, s, wordDict, dp);
//             if (ans)
//                 break;
//         }
//     }
//     return dp[i] = ans;
// }

bool f(int i, string s, vector<string> wordDict, vector<int> dp, string &ans)
{
    if (i == s.size())
        return true;
    int k, n;
    bool flag = false;
    if (dp[i] != -1)
        return dp[i];
    for (auto w : wordDict)
    {
        int k = i, n = w.size();
        int j;
        for (j = 0; j < n; j++)
            if (w[j] != s[k++])
                break;
        if (j == n)
        {
            ans += w + ',';
            flag = f(i + n, s, wordDict, dp, ans);
            if (flag)
                break;
        }
    }
    return dp[i] = flag;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    string ans = "";
    vector<int> dp(s.size() + 1, -1);
    bool flag = f(0, s, wordDict, dp, ans);
    if (flag)
    {
        cout << ans.substr(0,ans.size()-1) << endl;
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    string s = "abcd";
    vector<string> wordDict = {"a", "abc", "b", "cd"};
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}

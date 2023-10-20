#include <bits/stdc++.h>
using namespace std;

bool isPal(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void getPartition(int ind, string s, vector<string> &arr, vector<vector<string>> &ans)
{
    if (ind == s.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        if (isPal(s, ind, i))
        {
            arr.push_back(s.substr(ind, i - ind + 1));
            getPartition(i + 1, s, arr, ans);
            arr.pop_back();
            cout << s.substr(ind, i - ind + 1) << endl;
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> arr;
    getPartition(0, s, arr, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto ele : ans[i])
            cout << ele << "  ";
        cout << endl;
    }
    return 0;
}

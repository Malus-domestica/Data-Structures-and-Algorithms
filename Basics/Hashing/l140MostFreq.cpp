#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int n, k;
    cin >> n >> k;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        int presentSize = freq.size();
        if (freq[arr[i]] == 0 and presentSize == k)
            break;
        freq[arr[i]]++;
    }

    vector<pair<int, int>> ans;
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        if (it->second != 0)
        {
            // cout << it->first << " : " << it->second << endl;
            pair<int, int> p;
            p.first = it->second;
            p.second = it->first;
            ans.push_back(p);
            // cout << p.first << " : " << p.second << endl;
        }
    }

    sort(ans.begin(), ans.end(),greater<pair<int,int>>());

    for (int i = 0; i < k; i++)
    {
        cout << ans[i].first << " : " << ans[i].second << endl;
    }
    return 0;
}

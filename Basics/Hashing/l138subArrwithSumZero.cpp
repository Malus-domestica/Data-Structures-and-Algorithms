#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    // cout << "CHECK" << endl ;
    // prefix sum arr;
    vector<int> pref;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        pref.push_back(sum);
    }
    // cout << "CHECK" << endl;
    // mapping: calculating frequency of each sum
    map<int, int> countPrefSum;
    for (int i = 0; i < n; i++)
    {
        countPrefSum[pref[i]]++;
    }

    map<int, int>::iterator it;
    for (it = countPrefSum.begin(); it != countPrefSum.end(); it++)
    {
        cout << it->first << "  " << it->second << endl;
    }
    int ans = 0;
    for (it = countPrefSum.begin(); it != countPrefSum.end(); it++)
    {
        int c = it->second;
        ans += (c * (c - 1)) / 2;
        if (it->first == 0)
            ans += it->second;
    }
    cout << "Ans : " << ans << endl;
    return 0;
}

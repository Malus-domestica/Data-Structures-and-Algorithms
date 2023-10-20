#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, p, l;
    cin >> n >> p >> l;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        v[i].first = l - v[i].first;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int curr = p; // current fuel

    priority_queue<int, vector<int>> maxHeap;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr >= l)
            break; // distance can be travelled with the current fuel
        while (curr < v[i].first)
        {
            if (maxHeap.empty())
            {
                flag = 1;
                break;
            }
            ans++;
            curr += maxHeap.top();
            maxHeap.pop();
        }
        if (flag)
            break;
        maxHeap.push(v[i].second);
    }
    if (flag)
    {
        cout << "-1" << endl;
    }
    while (!maxHeap.empty() and curr < l)
    {
        curr += maxHeap.top();
        maxHeap.pop();
        ans++;
    }
    if (curr < l)
    {
        cout << "-1" << endl;
    }
    cout << ans << endl;
    return 0;
}

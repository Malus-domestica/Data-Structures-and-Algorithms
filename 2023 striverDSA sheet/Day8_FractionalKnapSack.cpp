#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, W;
    cin >> n >> W;
    vector<vector<int>> v;
    int val, wt;
    for (int i = 0; i < n; i++)
    {
        cin >> val >> wt;
        v.push_back({val, wt, val / wt});
    }
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
         { return a[2] > b[2]; });
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (W == 0)
            break;
        if (v[i][1] <= W)
        {
            W = W - v[i][1];
            sum += v[i][0];
        }
        else
        {
            sum += W * v[i][2];
            W -= W;
        }
    }
    cout << sum << endl;
    return 0;
}


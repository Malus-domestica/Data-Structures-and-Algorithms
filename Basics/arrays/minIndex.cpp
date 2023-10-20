// to find first occurence of repeated element
#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i, mn;
    mn = INT_MAX;

    const int N = 1e6 + 2;
    int idx[N];
    for (int i = 0; i < N; i++)
        idx[i] = -1;

    for (i = 0; i < n; i++)
    {
        if (idx[arr[i]] != -1)
            mn = min(mn, idx[arr[i]]);
        else
            idx[arr[i]] = i;
    }
    if(mn == INT_MAX ) cout<<"-1"<<endl;
    else
    cout << mn+1 << endl;
    return 0;
}
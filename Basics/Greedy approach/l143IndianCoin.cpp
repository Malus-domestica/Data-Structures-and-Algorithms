#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;//x is toatal to be made and n: is number of dinominations
    vector<int> arr(n);//dinominations
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += x / arr[i];
        x -= x / arr[i] * arr[i];
    }
    cout << ans << endl;
    return 0;
}

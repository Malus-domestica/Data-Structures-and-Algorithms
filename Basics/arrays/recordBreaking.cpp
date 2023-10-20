#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    int i, mx, ans = 0;
    mx = arr[0];
    arr[n] = -1;
    for (i = 0; i < n; i++)
    {
        // my logic
        //  if (mx <= arr[i])
        //  {
        //      mx = std::max(mx, arr[i]);
        //      if (i < n - 1 && mx > arr[i + 1])
        //      {
        //          ans++;
        //      }
        //  }
        if (arr[i] > mx && arr[i] > arr[i + 1])
        {
            ans++;
        }
        mx = max(mx, arr[i]);
    }
    cout << ans << endl;
    return 0;
}
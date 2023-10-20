#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int pdiff, i, j, len = 2, ans = 2;
    pdiff = arr[1] - arr[0];
    for (i = 1; i < n - 1; i++)
    {
        if (pdiff == arr[i + 1] - arr[i])
            len++;
        else
        {
            len = 2;
            pdiff = arr[i + 1] - arr[i];
        }
        ans = std::max(len, ans);
    }
    cout << ans << endl;
    return 0;
}
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
    int sum = 0, mn;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    mn = sum; // sum of first window
    for (int i = k; i < n; i++)
    {
        sum += (arr[i] - arr[i - k]);
        mn = min(sum, mn);
    }
    cout << "Ans: " << mn << endl;
    return 0;
}

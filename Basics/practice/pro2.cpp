#include <bits/stdc++.h>
using namespace std;
int gcd(int n1, int n2)
{
    int temp;
    if (n1 < n2)
    {
        temp = n2;
        n2 = n1;
        n1 = temp;
    }
    if (n2 == 0)
        return n1;
    int diff = n1 - n2;
    return gcd(diff, n2);
}
int lcm(int n1, int n2)
{
    int ans = 1;
    int temp;
    if (n1 < n2)
    {
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    for (int i = 2; i <= n1; i++)
    {
        if (n1 % i == 0 || n2 % i == 0)
        {
            ans *= i;
            if (n1 % i == 0)
                n1 = n1 / i;
            if (n2 % i == 0)
                n2 = n2 / i;
            cout << i << endl;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int ans = 0;
    cout << lcm(36, 30);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int diff = lcm(arr[i], arr[j]) - gcd(arr[i], arr[j]);
    //         if (diff == 0)
    //             ans++;
    //     }
    // }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void primeFact(int n)
{
    int spf[100] = {0}; // smallest prime factor
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == 0)
            spf[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                spf[j] = i;
            }
        }
    }

    while (n != 1)
    {
        cout << spf[n] << "  ";
        n = n / spf[n];
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    primeFact(n);
    return 0;
}

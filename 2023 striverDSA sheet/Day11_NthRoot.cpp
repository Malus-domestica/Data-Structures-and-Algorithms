#include <bits/stdc++.h>
using namespace std;

// return 1, if == m:
// return 0, if < m:
// return 2, if > m:
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    // Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// when ans in decimal places is asked
double multiply(double number, int n)
{
    double ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= number;
    }
    return ans;
}
double getNthRoot(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6; // for 5 decimal places
    while (high - low > eps)
    {
        double mid = (high + low) / 2;
        if (multiply(mid, n) < m)
            low = mid;
        else
            high = mid;
    }
    return low;
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
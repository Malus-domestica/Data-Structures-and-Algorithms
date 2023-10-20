#include <bits/stdc++.h>
using namespace std;

// int countPrimes(int n)
// {
//     int ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int cnt = 0;
//         for (int j = 1; j <= i; j++)
//         {
//             if (i % j == 0)
//                 cnt++;
//             if (cnt > 2)
//                 break;
//         }
//         if (cnt == 2)
//         {
//             // cout << i << endl;
//             ans++;
//         }
//     }
//     return ans;
// }

// sieve of erarosthenes : we'll make an array from 2 to n-1
// now initially we'll mark all of them as 1
// then will mark all multiples as zero
// at the sum will be returned
int countPrimes(int n)
{
    int ans = 0;
    vector<int> prime(n, 1);
    // i*i is taken because elements after i*i will already be marked
    for (int i = 2; i * i < n; i++)
    {
        if (prime[i] == 1)
        {
            // i*i is taken because elements before i*i are already be marked
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            ans++;
    }
    return ans;
}

// Solution below gives TLE

bool isPrime(int n)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int countPrimes(int n)
{
    int cnt = 0;

    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
            cnt++;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    cout << countPrimes(0) << endl;
    return 0;
}

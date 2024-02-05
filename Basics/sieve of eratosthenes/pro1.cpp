#include <bits/stdc++.h>
using namespace std;

int primeSeive(int n)
{
    // if(n==0 or n==1) return 0;
    vector<int> prime(n+1,0);

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    vector<int> prime_no;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            prime_no.push_back(i);
        }
    }
    int num=1;
    for(int i=0;i<prime_no.size();i++)
    {
        if(n%prime_no[i] == 0)
        {
            num = prime_no[i];
            break;
        }
    }
    int cnt = n / num;
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout<<primeSeive(n)<<endl;
    return 0;
}

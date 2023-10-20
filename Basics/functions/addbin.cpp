#include <iostream>
using namespace std;

int binAdd(int a, int b);
int reverse(int n);

int main()
{
    int bin1, bin2;
    cout << "Enter bin1 number" << endl;
    cin >> bin1;
    cout << "Enter bin2 number" << endl;
    cin >> bin2;
    cout<<"Answer: "<<binAdd(bin1, bin2)<<endl;
    return 0;
}

int binAdd(int a, int b)
{
    int ans = 0;
    int preCarry = 0;
    while (a > 0 && b > 0)
    {
        if (a % 2 == 0 && b % 2 == 0)
        {
            ans = ans * 10 + preCarry;
            preCarry = 0;
        }
        else if ((a % 2 == 1 && b % 2 == 0) || (a % 2 == 0 && b % 2 == 1))
        {
            if (preCarry == 1)
            {
                ans = ans * 10 + 0;
                preCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                preCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + preCarry;
            preCarry = 1;
        }
        a /= 10;
        b /= 10;
    }

    while (a > 0)
    {
        if (preCarry == 1)
        {
            if (a % 2 == 1)
            {
                ans = ans * 10 + 0;
                preCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                preCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (a % 2); // a%2 gives the last digit
        }
        a /= 10;
    }

    while (b > 0)
    {
        if (preCarry == 1)
        {
            if (b % 2 == 1)
            {
                ans = ans * 10 + 0;
                preCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                preCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (b % 2); // a%2 gives the last digit
        }
        b /= 10;
    }

    ans = ans * 10 + preCarry;
    ans = reverse(ans);
    return ans;
}

int reverse(int n)
{
    int ans = 0, lastDigit;
    while (n)
    {
        lastDigit = n % 10;
        ans = ans * 10 + lastDigit;
        n /= 10;
    }
    return ans;
}
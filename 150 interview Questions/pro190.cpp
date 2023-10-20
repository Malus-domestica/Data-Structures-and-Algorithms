#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    // char arr to store bits
    int temp;
    int ans = 0;
    uint32_t b = 2147483648;
    // for (int i = 0; i < 32; i++)
    // {
    //     temp = n % 2;
    //     n /= 2;
    //     ans += b * temp;
    //     b=b>>1;
    // }
    uint32_t a = 1;
    for (int i = 0; i < 32; i++)
    {
        temp = n & a;
        n = n >> 1;
        ans += temp << (31 - i);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << reverseBits(43261596) << endl;
    return 0;
}

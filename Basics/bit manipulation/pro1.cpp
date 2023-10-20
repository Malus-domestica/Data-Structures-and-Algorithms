//14.1
#include <bits/stdc++.h>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);//not equal to zero is used to return 1 or 0 from getBit()
}
// to make bit 1 at that pos
int setBit(int n, int pos)
{
    return (n | 1 << pos);
}

// clear bit at given pos
int clearBit(int n, int pos)
{
    return (n & (~(1 << pos)));
}

int main(int argc, char const *argv[])
{
    cout << getBit(10, 2) << endl;
    cout << clearBit(5, 2) << endl;
    return 0;
}

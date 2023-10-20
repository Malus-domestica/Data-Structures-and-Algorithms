// Count set bits in a number
#include <bits/stdc++.h>
using namespace std;

int countSetBit(int num)
{
    int count = 0;
    while (num)
    {
        num = num & num - 1;
        count++;
    }
    return count;
}

int main()
{
    cout << "Number of set bits: " << countSetBit(6) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n)
{
    int ans = 0;
    uint32_t b = 1;
    for (int i = 0; i < 32; i++)
    {
        ans += n & 1;
        n = n >> 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << hammingWeight(64) << endl;
    return 0;
}

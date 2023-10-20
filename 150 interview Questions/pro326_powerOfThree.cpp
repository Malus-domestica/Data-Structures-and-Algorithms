#include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n)
{
    return fmod(log10(n) / log10(3), 1) == 0;//fmod(x,y) gives x%y
}

int main(int argc, char const *argv[])
{
    int n = 28;
    cout << isPowerOfThree(n) << endl;
    return 0;
}

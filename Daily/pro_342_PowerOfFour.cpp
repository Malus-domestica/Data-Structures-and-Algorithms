#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        bool ans = false;
        int base = 4;
        while (n != 1)
        {
            if (n % 4 != 0)
                return false;
            n = n / 4;
        }
        return true;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) 
{
	return n>0 and  fmod(log2(abs(n)) / 2, 1) == 0;
}
};

int main(int argc, char const *argv[])
{
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int base = 1000000;

public:
    int Rabin_karp(string source, string target)
    {
        if (source == "" and target == "")
            return -1;

        int m = target.size();
        int power = 1;
        for (int i = 0; i < m; i++)
            power = (power * 31) % base;

        int targetCode = 0;
        for (int i = 0; i < m; i++)
        {
            targetCode = (targetCode * 31 + target[i]) % base;
        }
        int hashCode = 0;
        for (int i = 0; i < source.size(); i++)
        {
            hashCode = (hashCode * 31 + source[i]) % base;
            if (i < m - 1)
                continue;
            if (i >= m)
                hashCode = (hashCode - source[i - m] * power) % base;
            // cout<<i<<" : "<<hashCode<<endl;
            if (hashCode < 0)
                hashCode += base;
            if (hashCode == targetCode)
            {
                if (source.substr(i - m + 1, m) == target)
                    return i - m + 1;
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b)
    {
        if (a == b)
            return 1;
        int count = 1;
        string source = a;
        while (source.size() < b.size())
        {
            count++;
            source += a;
        }
        if (a == b)
            return 1;

        if (Rabin_karp(source, b) != -1)
            return count;
        if (Rabin_karp(source + a, b) != -1)
            return count + 1;
        return -1;
    }
};
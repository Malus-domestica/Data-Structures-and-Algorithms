#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    if (needle == "")
        return 0;
    vector<int> lps = {0};

    int prevLps = 0, i = 1;
    int n = needle.size();

    while (i < n)
    {
        if (needle[i] == needle[prevLps])
        {
            lps[i] = prevLps + 1;
            prevLps += 1;
            i++;
        }
        else
        {
            if (prevLps == 0)
                lps[i++] = 0; 
            else
                prevLps = lps[prevLps - 1];
        }
    }

    i = 0;     // ptr for haystack
    int j = 0; // ptr for needle
    while (i < haystack.size())
    {
        if (needle[j] == haystack[i])
            i++, j++;
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
        if (j == n)
            return i - n;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    return 0;
}

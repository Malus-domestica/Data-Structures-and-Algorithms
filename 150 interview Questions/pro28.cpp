#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int i, j;
    int l = haystack.size();
    int m = needle.size();
    for (i = 0, j = 0; i < l; i++)
    {
        int k=i;
        if (haystack[i] == needle[0])
        {
            for (j = 0; j < m,i < l; j++, i++)
            {
                if (needle[j] != haystack[i])
                    break;
            }
            if(j==m)return i-j;
            i=k;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string haystack = "mississippi";
    string needle = "issip";
    cout << strStr(haystack, needle) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string v1, string v2)
    {
        int ans = 0;
        int n1 = v1.size(), n2 = v2.size();

        for (int i = 0, j = 0; i < n1 || j < n2; ++i, ++j)
        {

            double s1 = 0, s2 = 0;

            while (i < n1 && v1[i] != '.')
            {
                s1 += s1 * 10 + (v1[i++] - 48);
            }
            while (j < n2 && v2[j] != '.')
            {
                s2 += s2 * 10 + (v2[j++] - 48);
            }
            cout << s1 << " " << s2 << endl;
            if (s1 < s2)
                return -1;
            else if (s2 < s1)
                return 1;
        }

        return 0;
    }
};
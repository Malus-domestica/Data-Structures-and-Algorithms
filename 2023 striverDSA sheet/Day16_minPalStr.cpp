#include <bits/stdc++.h>
using namespace std;

int solve(string A)
{
    int len = A.size();

    string rev_A = A;
    reverse(rev_A.begin(), rev_A.end());
    string needle = A + "&" + rev_A;

    // lps
    

    int prevLps = 0, i = 1;
    int n = needle.size();
    vector<int> lps(n,0) ;

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
    for (int i = 0; i < needle.size(); i++)
        cout << lps[i] << " ";
    cout << endl;
    return len - lps[n - 1];
}

int main(int argc, char const *argv[])
{
    string A = "aaaaa";
    cout << solve(A) << endl;
    return 0;
}

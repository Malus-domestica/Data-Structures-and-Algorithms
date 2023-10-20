#include <bits/stdc++.h>
using namespace std;
// Given an array A of 0s and 1s, we may change up to K values from 0 to 1
// Return the length of the longest contiguous subarray that contains only ones
// Idea
// Find the longest subarray with atmost k zeroes
// For each A[j], try to find the longest subarray
// if  A[i] ~ A[j] has zeroes <= k, we continue to increase j.
// if  A[i] ~ A[j] has zeroes > k, we  increase i as well as j.

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int zerocount = 0, i = 0, ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
            zerocount++;
        while (zerocount > k)
        {
            if (a[i] == 0)
                zerocount--;
            i++;
        }
        // zerocount <= k
        ans = max(ans, (j - i + 1));
    }
    cout << ans << endl;
    return 0;
}

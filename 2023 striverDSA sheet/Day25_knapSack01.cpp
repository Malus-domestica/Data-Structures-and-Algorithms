#include <bits/stdc++.h>
using namespace std;

int f(int ind, int w, vector<int> eleWts, vector<int> eleVals)
{
    if (ind == 0)
    {
        if (eleWts[0] <= w)
            return eleVals[0];
        else
            return 0;
    }
    // not take
    int a, b = INT_MIN;
    a = f(ind - 1, w);
    // take
    if (w >= eleWts[ind])
    {
        b = eleVals[ind] + f(ind - 1, w - eleWts[ind], eleWts, eleVals);
    }
    return max(a, b);
}
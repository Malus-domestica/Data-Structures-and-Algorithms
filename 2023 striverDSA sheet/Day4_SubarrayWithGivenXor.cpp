#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int k)
{
    int n = a.size(); // size of the given array.
    int xr = 0;
    map<int, int> mpp; // declaring the map.
    mpp[xr]++;         // setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        // By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{

    return 0;
}
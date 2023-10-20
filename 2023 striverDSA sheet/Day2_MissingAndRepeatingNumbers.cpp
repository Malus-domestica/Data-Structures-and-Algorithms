#include <bits/stdc++.h>
using namespace std;

vector<int> rep(vector<int> A)
{
    // since we are summing up so sum might exceed int
    long long s1, s2, arr_sum = 0, arr_sqr_sum = 0;
    int n = A.size();

    s1 = (n * (n + 1)) / 2;           // sum of natural numbers
    s2 = (n * (n + 1) * (n + 2)) / 6; // sum of squares of natural number

    for (int i = 0; i < n; i++)
    {
        arr_sum += A[i];
        arr_sqr_sum += (long long)(A[i] * A[i]);
    }
    long long Z = arr_sum - s1;
    long long W = arr_sqr_sum - s2;
    int X, Y;
    X = (Z + W / Z) / 2;
    Y = X - Z;
    return {(int)X, (int)Y};
}

//strivers solution
vector<int> repeatedNumber(const vector<int> &a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;
//Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};   
    
}


int main(int argc, char const *argv[])
{
    vector<int> ans;
    ans = rep({3, 1, 2, 5, 3});
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}

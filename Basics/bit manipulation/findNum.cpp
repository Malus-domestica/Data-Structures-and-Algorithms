#include <bits/stdc++.h>
using namespace std;

// example
/*
{2,4,3,4,2}
2^4^3^4^2

010
100
011
100
010
*/

int uniqueNum(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
}

int main()
{
    int arr[] = {2, 3, 4, 2, 4, 2};
    cout << uniqueNum(arr, 5) << endl;
    return 0;
}

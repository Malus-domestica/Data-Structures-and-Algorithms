#include <bits/stdc++.h>
#include <climits>
using namespace std;
// get max sub array sum
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int i, j, k;

    // int cumSum[n + 1];
    // cumSum[0] = 0;
    // for (int i = 1; i < n + 1; i++)
    // {
    //     cumSum[i] = cumSum[i - 1] + a[i - 1];
    // }
    int mx = INT_MIN;
    int curSum = 0;
    // function  complexity n
    for (int i = 0; i < n; i++)
    {
        curSum += a[i];
        if (curSum < 0)
            curSum = 0;
        mx = max(mx, curSum);
    }
    cout << mx << endl;
    return 0;
}
// function  complexity n^3
//  for (i = 0; i < n; i++)
//  {
//      for (j = i; j < n; j++)
//      {
//          int sum = 0;
//          for (k = i; k <= j; k++)
//  cout << a[k] << "  ";
//  sum += a[k];
//  cout << endl;
//  mx = max(mx, sum);
//  }
//  cout << endl;
//  }

// funtion Complexity n^2
//  for (int i = 1; i <= n; i++)
//  {
//      int sum = 0;
//      for (int j = 0; j < i; j++)
//      {
//          sum = cumSum[i] - cumSum[j];
//          mx = max(mx, sum);
//      }
//  }
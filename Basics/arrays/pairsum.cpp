#include <bits/stdc++.h>
#include <climits>
using namespace std;
// get max sub array sum
// provided array is sorted
int main(int argc, char const *argv[])
{
    int n, s;
    bool check = false;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // brute force algo
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (a[i] + a[j] == s)
    //         {
    //             check = true;
    //             break;
    //         }
    //     }
    //     if (check == true)
    //         break;
    // }
    // if (check == true)
    //     cout << "Found the sum" << endl;
    // else
    //     cout << "Sum not found" << endl;

    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] == s)
        {
            check = true;
            break;
        }
        else if ((a[i] + a[j]) > s)
            j--;
        else
            i++;
    }
    if (check == true)
        cout << "Found the sum" << endl;
    else
        cout << "Sum not found" << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
//using binary search
int mySqrt(int x)
{
    if (x == 0)
        return 0;
    int low, high, mid;
    // O(logn)binary search
    low = 1, high = x;
    while (low <= high)
    {
        mid = (low + high) / 2;
        cout << mid << "  " << x / mid << endl;
        if (mid== x / (mid+1) || mid ==x/mid)//floor values are taken
            return mid;
        else if (mid > x / mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    cout << mySqrt(n) << endl;
    return 0;
}

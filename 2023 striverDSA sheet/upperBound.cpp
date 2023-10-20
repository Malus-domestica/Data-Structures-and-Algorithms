#include <bits/stdc++.h>
using namespace std;

int upperBound(int x, vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans; // index of element is returned
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
    cout << upperBound(13, arr) << endl;
    return 0;
}

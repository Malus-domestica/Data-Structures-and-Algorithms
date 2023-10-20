#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPeakElement(const vector<int> &num)
    {
        int n = arr.size(); // Size of array.

        // Edge cases:
        if (n == 1)
            return 0;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // If arr[mid] is the peak:
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;

            // If we are in the left:
            if (arr[mid] > arr[mid - 1])
                low = mid + 1;

            // If we are in the right:
            // Or, a[mid] is minima
            else
                high = mid - 1;
        }
        // Dummy return statement
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}

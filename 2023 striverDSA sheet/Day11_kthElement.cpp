#include <bits/stdc++.h>
using namespace std;

int kthelement(int arr1[], int arr2[], int m, int n, int k)
{
    if (m > n)
    {
        return kthelement(arr2, arr1, n, m, k);
    }

    int low = max(0, k - m), high = min(k, n);

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 1;
}

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    // keeping arr2 as shorter
    if (n < m)
    {
        return kthElement(arr2, arr1, m, n, k);
    }
    if ((m + n) < k)
        return INT_MAX;
    int l1, l2, r1, r2;

    // keep int pointer l and r on shorter array
    int l = 0;
    int r = m - 1;
    int total = n + m;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int i = k - mid - 2;

        l1 = i >= 0 ? arr1[i] : INT_MIN;
        l2 = mid >= 0 ? arr2[mid] : INT_MIN;
        r1 = (i + 1) < n ? arr1[i + 1] : INT_MAX;
        r2 = (mid + 1) < m ? arr2[mid + 1] : INT_MAX;

        if (l1 < r2 and l2 < r1)
        {
            return max(l1, l2);
        }
        else if (l2 > r1)
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return 0;
}

int main()
{
    int array1[] = {100, 112, 256, 349, 770};
    int array2[] = {72, 86, 113, 119, 265, 445, 892};
    int m = sizeof(array1) / sizeof(array1[0]);
    int n = sizeof(array2) / sizeof(array2[0]);
    int k = 7;
    cout << kthElement(array1, array2, m, n, k) << endl;
    // cout << "The element at the kth position in the final sorted array is "
    //      << kthelement(array1, array2, m, n, k);
    return 0;
}
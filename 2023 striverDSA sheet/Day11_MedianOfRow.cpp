#include <bits/stdc++.h>
using namespace std;
int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}

int findMedian(vector<vector<int>> &A)
{
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += (upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin());
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}


int median(vector<vector<int>> &A, int l, int h) {
    // Write your code here.
     int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += (upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin());//matrix when arranges in asc array the element just before median gives the answer
        }
        if (cnt <= (n * m) / 2)//(n*m)/2 number of elements on either side of median
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int row = 3, col = 3;
    vector<vector<int>> arr = {{1, 3, 8},
                               {2, 3, 4},
                               {1, 2, 5}};
    cout << "The median of the row-wise sorted matrix is: " << findMedian(arr) << endl;
    return 0;
}
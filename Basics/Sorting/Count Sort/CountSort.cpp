#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n)
{
        // find max in order to make count array odf that size+1
    int mx = arr[0];
    for (int i = 0; i < n; i++)
        mx = max(arr[i], mx);

    // make count array
    int countArr[10] = {0};
    for (int i = 0; i < n; i++)
        countArr[arr[i]]++;

    // modify count array
    for (int i = 1; i <= mx; i++)
        countArr[i] += countArr[i - 1];

    // now make new array to contain sorted element
    int newArr[n];
    for (int i = n - 1; i >= 0; i--)
        newArr[--countArr[arr[i]]] = arr[i];

    // now store newArr in arr
    for (int i = 0; i < n; i++)
        arr[i] = newArr[i];
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    countSort(arr, 9);
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

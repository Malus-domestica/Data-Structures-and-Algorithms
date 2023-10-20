#include <iostream>
using namespace std;

bool sortedArr(int arr[], int n)
{
    // base condition
    if (n == 1)
        return true;
    if (arr[0] < arr[1] && sortedArr(arr + 1, n - 1))
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << sortedArr(arr, n) << endl;
    return 0;
}

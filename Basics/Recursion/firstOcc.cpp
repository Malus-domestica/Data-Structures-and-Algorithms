#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
        return -1;
    if (arr[i] == key)
        return i;
    return firstocc(arr, n, i + 1, key);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << firstocc(arr, n, 0, 2) << endl;
    return 0;
}

#include <iostream>
using namespace std;
// Linear Search

int linearSearch(int arr[], int n, int key);

int main(int argc, char const *argv[])
{
    int n, key;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter key: ";
    cin >> key;

    int check = linearSearch(arr, n, key);
    if (check != -1)
        cout << "Found At Index: " << linearSearch(arr, n, key) << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}

//time complexity O(n)

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
            return i;
    }
    return -1;
}
#include <iostream>
using namespace std;
// Linear Search

int binarySearch(int arr[], int n, int key);

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

    int check = binarySearch(arr, n, key);
    if (check != -1)
        cout << "Found At Index: " << check << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}

//time complexity O(n)

int binarySearch(int arr[], int n, int key)
{
    int s=0;
    int e=n-1;
    int mid;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid] == key) return mid;
        else if (arr[mid] > key) e = mid - 1;
        else s = mid + 1;
    }   
    return -1;
}
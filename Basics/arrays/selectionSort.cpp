#include <iostream>
#include <climits>
using namespace std;
// Selection Sort

void selectionSort(int arr[], int n);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    selectionSort(arr, n);
    return 0;
}


void selectionSort(int arr[], int n)
{
    int min, min_index, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = min;
        arr[min_index] = temp;
        cout << arr[i] << endl;
    }
    // print
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}
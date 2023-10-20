#include <iostream>
#include <climits>
using namespace std;
// Insertion Sort

void insertionSort(int arr[], int n);
void shift(int arr[], int i, int j);
void display(int arr[], int n);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);
    return 0;
}

void insertionSort(int arr[], int n)
{
    int currentElement, i, j;
    // start from second element considering it is ordered till first
    for (i = 1; i < n; i++)
    {
        currentElement = arr[i];
        int j = i-1;
        while(currentElement<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[++j] = currentElement;
    }
    //display
    for(int k = 0;k <n;k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}
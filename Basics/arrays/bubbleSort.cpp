#include <iostream>
#include <climits>
using namespace std;
// Selection Sort

void bubbleSort(int arr[], int n);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort(arr, n);
    return 0;
}


void bubbleSort(int arr[], int n)
{
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j =0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }    
    // print
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}
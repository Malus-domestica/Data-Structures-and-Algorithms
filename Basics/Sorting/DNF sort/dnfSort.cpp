#include <iostream>
using namespace std;

void dnf(int arr[], int n)
{
    int low, mid, high, temp;
    low = mid = 0, high = n - 1;
    // move mid ptr on unsorted array
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else  
        {
            temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};

    dnf(arr, 9);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}

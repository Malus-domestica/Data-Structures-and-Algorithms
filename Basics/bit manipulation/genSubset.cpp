// Write a program to generate all possible subset of a set
#include <bits/stdc++.h>
using namespace std;

int getbit(int num, int pos)
{
    return ((num & (1 << pos)) != 0);
}

void subset(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (getbit(i, j))
            {
                cout << " " << arr[j];
            }
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int arr[3] = {1, 2, 3};
    subset(arr, 3);
    return 0;
}
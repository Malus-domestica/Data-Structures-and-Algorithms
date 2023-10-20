#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    while (i < n and j < n)
    {
        if (arr[i] <= dep[j]) // if arrival train came before departure of dep train
        {
            plat_needed++;
            i++;
        }
        else if (arr[i] > dep[j]) // if arrival train came after dep train
        {
            plat_needed--;
            j++;
        }
        if (result < plat_needed)
            result = plat_needed;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    return 0;
}

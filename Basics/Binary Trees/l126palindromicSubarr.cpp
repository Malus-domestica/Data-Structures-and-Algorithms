#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num)
{
    int ans = 0, rem, n = num;

    while (num)
    {
        rem = num % 10;
        ans = ans * 10 + rem;
        num = num / 10;
    }
    if (ans == n)
        return true;
    else
        return false;
}

int findPalindromicSubarray(vector<int> arr, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }

    if (isPalindrome(num))
    {
        return 0; // starting index
    }

    for (int j = k; j, arr.size(); j++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];

        if (isPalindrome(num))
        {
            return j - k + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;
    int ans = findPalindromicSubarray(arr, k);
    if (ans == -1)
        cout << "Palindromic subarray does not exits" << endl;
    else
    {
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
    return 0;
}

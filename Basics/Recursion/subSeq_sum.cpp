#include <bits/stdc++.h>
using namespace std;

void print_sub(int n, vector<int> data, int i, vector<int> arr, int sum, int k)
{
    if (i == n)
    {
        if (sum == k)
        {
            for (int i = 0; i < arr.size(); i++)
                cout << arr[i] << "  ";
            cout << endl;
        }
        return;
    }
    else
    {
        arr.push_back(data[i]);
        sum += data[i];
        print_sub(n, data, i + 1, arr, sum, k);
        arr.pop_back();
        sum -= data[i];
        print_sub(n, data, i + 1, arr, sum, k);
    }
}
int main(int argc, char const *argv[])
{
    vector<int> data = {1, 2, 1};
    int n = 3;
    int k = 2;
    vector<int> arr = {};
    print_sub(n, data, 0, arr, 0, k);
    return 0;
}

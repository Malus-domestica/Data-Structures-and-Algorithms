#include <iostream>
#include <climits>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

        int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mx = std::max(mx, arr[i]);
        cout<<"Max: "<<mx<<endl;
    }
    return 0;
}

#include<iostream>
using namespace std;

int lastocc(int arr[], int n, int i, int key){
    if(i==n)return -1;
    int pos = lastocc(arr,n,i+1,key);
    if(pos!=-1)return pos;
    if(arr[i]==key) return i;
    else return -1;

}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << lastocc(arr, n, 0, 2) << endl;
    return 0;
}

/*
    1
   212
  32123
*/

#include <iostream>
using namespace std;

int main()
{
    int row, i, j;
    cin >> row;
    for(i = 1; i <= row; i++){
        for(j = 1; j<=row-i; j++)cout<<" ";
        for(j = i; j >= 1; j--)cout<<j<<"";
        for(j = 2; j<= i; j++) cout<<j<<"";
        cout<<endl;
    }
    return 0;
}
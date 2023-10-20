/*
    *
   ***
  *****
   ***
    *

*/

#include <iostream>
using namespace std;

int main()
{
    int row,odd, i, j;
    cin >> row;\
    //upper
    for(i = 1; i <= row; i++){
        for(j = 1; j<=row-i; j++)cout<<"  ";
        for(j = 1; j <= i*2-1; j++)cout<<"* ";
        cout<<endl;
    }
    //lower
    for(i = row; i >= 1; i--){
        for(j = 1; j<=row-i; j++)cout<<"  ";
        for(j = 1; j <= i*2-1; j++)cout<<"* ";
        cout<<endl;
    }
    return 0;
}
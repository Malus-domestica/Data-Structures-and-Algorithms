/*
   ****
  ****
 ****
****

every column will have two loops 
one for star
one for spaces
*/

#include <iostream>
using namespace std;

int main()
{
    int row, i, j;
    cin >> row;
    for(i = 1; i <= row; i++){
        for(j = 1; j<=row-i; j++)cout<<"  ";
        for(j = 1; j<= row; j++) cout<<"* ";
        cout<<endl;
    }
    return 0;
}
/*
  
  *   *
 * * * *
*   *   *
row = 3
for star we have multiples of 4 and if row is 2 and col is multiple of 4 then also we have to print star
*/

#include <iostream>
using namespace std;

int main()
{
    int col,odd, i, j;
    cin >> col;
    for(i = 1; i <= 3; i++){
        for(j = 1; j <= col; j++){
            if( ( (i+j)%4 == 0 ) || ( i==2 && (j%4==0) )) cout<<"* ";
            else cout<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
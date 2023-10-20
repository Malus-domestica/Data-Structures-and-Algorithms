/*
if we add indices for 1s we get even number
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/

#include <iostream>
using namespace std;

int main()
{
    int n, i, j;
    cin >> n;
    for(i = 1; i <= n; i++){
        for(j = 1;j<=i;j++){
            if((i+j)%2 == 0)cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}

// int main()
// {
//     int n, i, j;
//     cin >> n;
//     for(i = 1; i <= n; i++){
//         if(i%2 == 0){
//             for(j = 1; j <= i ;j++){
//                 if(j%2 == 0)cout<<"1 ";
//                 else cout<<"0 ";
//             }
//         }
//         else{
//             for(j = 1; j <= i ;j++){
//                 if(j%2 == 0)cout<<"0 ";
//                 else cout<<"1 ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }
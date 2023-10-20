/*
*    *
**  **
******
**  **
*    *
 */

#include <iostream>
using namespace std;


int main()
{
    int n, i, j;
    cin >> n;
    //upper
    for(i = 1; i <= n; i++){
        for(j = 1; j<=i; j++) cout<<"*";
        int space = 2*n - 2*i;
        for(j = 1; j<=space ; j++) cout<<" ";
        for(j = 1; j<=i; j++) cout<<"*";
        cout<<endl;
    }
    //lower
    for(i = n; i >= 1; i--){
        for(j = 1; j<=i; j++) cout<<"*";
        int space = 2*n - 2*i;
        for(j = 1; j<=space ; j++) cout<<" ";
        for(j = 1; j<=i; j++) cout<<"*";
        cout<<endl;
    }
    return 0;
}

//my logic
// int main()
// {
//     int n, i, j;
//     cin >> n;
//     //upper
//     for(i = 1; i <= n; i++){
//         for(j = 1; j <= n*2 ; j++){
//             if(j > i && j <= (n*2 -i)) cout<<" ";
//             else cout<<"*";
//         }
//         cout<<endl;
//     }
//     //lower
//     for(i = n; i >= 1; i--){
//         for(j = 1; j <= n*2 ; j++){
//             if(j > i && j <= (n*2 -i)) cout<<" ";
//             else cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }